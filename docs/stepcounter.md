# 👟 Step Counter
 
## Overview
 
The step count shown on the watch face comes from a hardware timer interrupt (`TIMER4`) paired with a threshold detector running on the **MPU6050**'s accelerometer data. This page documents that pipeline: how it's wired up in `main.c`, what it reads, and what its detection thresholds are.
 
## Hardware
 
The **MPU6050** is a 6-axis accelerometer + gyroscope, talking I2C1 on `PA15` (`SCL`) / `PB7` (`SDA`). See [Architecture documentation](./architecture.md#pin-mapping). `main.c` initialises it with:
 
```c
MPU6050_Init(&MPU6050_Data, GPIOA, GPIO_PIN_0, MPU6050_Device_0,
             MPU6050_Accelerometer_8G, MPU6050_Gyroscope_2000s);
```
 
- **`MPU6050_Device_0`**: The sensor's `AD0` pin is wired low, putting it at I2C address `0xD0`.
- **`MPU6050_Accelerometer_8G`** / **`MPU6050_Gyroscope_2000s`**: The widest available ranges on both axes; sensible for a wrist-worn device that can see fairly sharp accelerations.

## Live path: timer interrupt + threshold detection
 
This is the step counter that actually runs on the watch. `main.c` arms a periodic hardware timer during initialisation:
 
```c
BSP_TIMER_run_us(TIMER4_ID, 30000, true); // fires every 30 ms
```

Each time it fires, the interrupt handler (`TIMER4_user_handler_it`, in `stm32g4_timer.c`) does the following:
 
1. Calls `MPU6050_ReadAll()` to refresh `MPU6050_Data`.
2. Combines all three axes into a single magnitude: `abs(X) + abs(Y) + abs(Z)`; a sum of absolute values.
3. Compares that magnitude against a threshold (`SEUIL`).
4. If it's above threshold, **and** a debounce flag (`dans_pic`) confirms this isn't the same peak as last time, **and** at least `TEMPS_MORT` has passed since the last accepted step (`HAL_GetTick()`-based), increments the global `pas_interupt` counter and sets `dans_pic = true`.
5. Once the magnitude drops back under the threshold, `dans_pic` is reset to `false`, arming the detector for the next step.

```c
int32_t magnitude = abs(MPU6050_Data.Accelerometer_X)
                   + abs(MPU6050_Data.Accelerometer_Y)
                   + abs(MPU6050_Data.Accelerometer_Z);
 
if (magnitude > SEUIL) {
    if (!dans_pic && (maintenant - dernier_pas_timestamp > TEMPS_MORT)) {
        pas_interupt++;
        dans_pic = true;
        dernier_pas_timestamp = maintenant;
    }
} else {
    dans_pic = false;
}
```
 
`SEUIL` and `TEMPS_MORT` are defined in `stm32g4_timer.h`:
 
```c
#define SEUIL       4500
#define TEMPS_MORT  200
```

```c
volatile uint16_t pas_interupt = 0; // declared in main.c
```
 
`pas_interupt` is then read directly by the display layer every time the idle screen refreshes:
 
```c
EPD_Display_Idle(pas_interupt); // in check_and_update_time_display() and the IDLE state
```

| Parameter                | Value                              |
|----------------------------|---------------------------------------|
| Timer period               | `30 ms`        |
| Threshold (`SEUIL`)        | `4500` |
| Debounce (`TEMPS_MORT`)    | `200 ms`|
| Axes used                  | All 3: `abs(X) + abs(Y) + abs(Z)`|
