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

Each time it fires, an interrupt handler (`TIMER4_user_handler_it`, in `stm32g4_timer.c` is expected to:
 
1. Call `MPU6050_ReadAll()` to refresh `MPU6050_Data`.
2. Look only at `MPU6050_Data.Accelerometer_X`; a single axis, not the full 3-axis norm.
3. Compare it against a threshold (`SEUIL`, reported as `1500`).
4. If it's above threshold, **and** a debounce flag (`dans_pic`) confirms this isn't the same peak as last time, **and** at least `TEMPS_MORT` (`200 ms`, reported) has passed since the last accepted step, increment the global `pas_interupt` counter.

```c
volatile uint16_t pas_interupt = 0; // declared in main.c
```
 
`pas_interupt` is then read directly by the display layer every time the idle screen refreshes:

```c
EPD_Display_Idle(pas_interupt); // in check_and_update_time_display() and the IDLE state
```

| Parameter                | Value                                 |
|----------------------------|---------------------------------------------------|
| Timer period               | `30 ms` |
| Threshold (`SEUIL`)        | `1500` |
| Debounce (`TEMPS_MORT`)    | `200 ms` |
| Axis used                  | `X` only                                          |
