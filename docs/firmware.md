# 🛠️ Firmware
 
## Overview
 
Tictac runs **bare-metal**: there's no RTOS, no tasks, no scheduler. `main()` boils down to a single infinite loop calling one function over and over:

```c
int main(void) {
    while (1) {
        stateMachine();
    }
}
```

Concurrency comes entirely from hardware interrupts layered on top of that loop: the rotary encoder reacts to GPIO/EXTI events, and the step counter reacts to a periodic hardware timer (see [Step Counter documentation](./stepcounter.md)), while everything else (buttons, Bluetooth, the clock) is handled by polling inside the loop itself.

## Main State Machine
 
`stateMachine()` in `main.c` implements a 4-state machine:
 
> [!NOTE]
> The block diagram is coming soon...

| State        | Entered when                          | Does                                                          | Leads to       |
|----------------|------------------------------------------|------------------------------------------------------------------|------------------|
| **`INIT`**     | Once, at boot                            | Initialises every peripheral and driver (see below)             | `IDLE`           |
| **`IDLE`**     | Right after `INIT`, or when leaving `MENU` | Resets and redraws the idle screen, snapshots the current time/date | `DETECTION` (immediately) |
| **`DETECTION`**| Right after `IDLE`                       | Polls Bluetooth (`handle_uart_reception()`), refreshes the clock if it changed, polls the central button | `MENU` on button press, otherwise stays |
| **`MENU`**     | Central button press detected in `DETECTION` | Delegates entirely to `EPD_StateMachine()` (see [HMI documentation](./hmi.md)) | `IDLE` once `EPD_StateMachine()` returns `1` |

An unrecognised `currentState` value falls into a `default` case that resets straight back to `INIT`, meaning a corrupted state variable would silently replay the entire initialisation sequence rather than crash, harmless given that most of the init calls are idempotent register writes.

## Initialisation Sequence
 
Everything happens inside the `INIT` case, in this order:
 
1. **`HAL_Init()`**: STM32 HAL startup.
2. **`BSP_GPIO_enable()`**: Enables the GPIO clocks.
3. **UART2** (`115200` baud): Initialised and wired to `printf()` via `BSP_SYS_set_std_usart()`. Every debug message in the firmware goes through here (see [Architecture documentation](./architecture.md#software-peripheral-configuration)).
4. **UART1** (`115200` baud): The HC-05 Bluetooth link (see [Connectivity documentation](./connectivity.md)).
5. **ADC** (`BSP_ADC_init()`): Shared between the HW827 pulse sensor's channel and any other enabled analog input.
6. **RTC** (`RTC_Init()`): See below.
7. **MPU6050** (`MPU6050_Init()`): Accelerometer/gyroscope, `±8 g` / `±2000 °/s` (see [Step Counter documentation](./stepcounter.md)). A failed init here halts the firmware in an infinite `while(1);`. There's no fallback or retry, the watch simply locks up.
8. **`TIMER4`** (`BSP_TIMER_run_us(TIMER4_ID, 30000, true)`): Periodic interrupt feeding the step counter (see [Step Counter documentation](./stepcounter.md)).
9. **Encoder + central button GPIOs**: `PA12`/`PB5` configured with `EXTI` (rising+falling, pull-up); `PA11` (central button) configured as a polled input (pull-down).
10. **EXTI callbacks**: `encoder_callback` registered for both pin `12` and pin `5` via `BSP_EXTIT_set_callback()`.
11. **`lastEncoded = readEncoder();`**: See the note below.
12. **HW827** (`HW827_Init()`): Pulse sensor ADC setup (see [Heart-Rate documentation](./heartrate.md)).
13. **E-paper**: `EPD_SPI_Init()`, `DEV_Module_Init()`, `EPD_Init()`, then `EPD_DisplayBaseImage()` to draw the very first frame.

## Concurrency model: interrupts vs. polling
 
| Mechanism                       | Source                  | Handles                                          |
|-----------------------------------|----------------------------|-----------------------------------------------------|
| EXTI (`PA12`, `PB5`)              | Rotary encoder phases      | Direction detection ➜ `EPD_MenuEncoderCallback()`   |
| Hardware timer (`TIMER4`, `30 ms`)| Periodic, configured in `main.c` | Step detection: 3-axis magnitude threshold (see [Step Counter documentation](./stepcounter.md)) |
| Polling, every `DETECTION` iteration | `handle_uart_reception()` | Bluetooth message reception (see [Connectivity documentation](./connectivity.md)) |
| Polling, every `DETECTION` iteration | `check_and_update_time_display()` | Idle-screen clock refresh |
| Polling, every `DETECTION` iteration | `read_central_button()`   | Menu entry                                         |

## Rotary Encoder Integration
 
The encoder's two quadrature phases are wired to `PA12`/`PB5` (see [Architecture documentation](./architecture.md#pin-mapping)), and direction detection happens entirely inside `encoder_callback()`, fired by EXTI on either pin:
 
1. A `5 ms` software debounce (`HAL_GetTick()`-based) rejects interrupts firing too close together.
2. The two pin states are combined into a 2-bit "Gray code" state (`pinA << 1 | pinB`).
3. A `switch` on the *previous* state determines whether the *new* state represents a clockwise or counter-clockwise step.
4. On a confirmed direction, `EPD_MenuEncoderCallback()` is called: direction `1` calls it with `-1`, and direction `-1` calls it with `+1`.

```c
if (direction == 1) {
    encoderPos++;
    EPD_MenuEncoderCallback(-1);
} else if (direction == -1) {
    encoderPos--;
    EPD_MenuEncoderCallback(1);
}
```

## Central Button
 
`read_central_button()` is polled once per `DETECTION` loop iteration. It debounces in software by timestamping the last valid press and requiring `50 ms` (`DEBOUNCE_TIME`) to pass before accepting a new one, and only fires on the rising edge. A single physical press returns `true` exactly once, regardless of how long the button stays held.

## Real-Time Clock
 
`RTC_Init()` does three things: initialise the RTC peripheral, **write** a hardcoded default time/date (`00:00:00`, Saturday, January 1st) to it, then immediately read it back into the same `time`/`date` globals declared in `rtc.h`.

```c
RTC_TimeTypeDef time = {0, 00, 00};
RTC_DateTypeDef date = {SATURDAY, JANUARY, 1, 00};
```

`RTC_GetDate()` / `RTC_GetHeure()` simply re-read the RTC and format it into static buffers (`"Lun 15/05"`, `"14:30"`) for the idle screen (see [HMI documentation](./hmi.md)).
 
These exact same `time` / `date` globals are also the ones written to by the Bluetooth `'z'` command (see [Connectivity documentation](./connectivity.md#supported-commands)): a phone-side time sync and the watch face's clock are reading and writing the same two structs.
