# ⚙️ Hardware Architecture
 
## Overview
 
Tictac is built around an **STM32G431KB** (Cortex-M4F), which handles everything: the e-paper
display via SPI, the accelerometer via I2C, the pulse sensor via ADC, Bluetooth and debug
console via UART, and GPIO/EXTI for the buttons and rotary encoder.
 
### Why the G431KB?
 
This was the microcontroller imposed by the academic framework the project was built under
(a Nucleo-G431KB board), so "why this chip" wasn't really a choice we made
freely. It turned out to be a genuinely good fit: a single chip exposing SPI, I2C,
two independent UARTs and a 12-bit ADC covers every peripheral the watch needs; e-paper,
accelerometer, pulse sensor, Bluetooth. The Cortex-M4F core
also brings a hardware FPU, which is put to use in the floating-point band-pass filtering applied
to both the PPG and the accelerometer signals (see [Heart-rate documentation](./heartrate.md) and
[Step Counter documentation](./stepcounter.md)).

## Two hardware platforms
 
Like most projects, Tictac went through two distinct hardware stages:
 
- A **Nucleo-G431KB**, plugged into the school's generic prototyping baseboard, used to validate firmware and sensors before any custom PCB existed.
- A fully custom **2-layer PCB**, designed in Altium Designer around the bare
  **STM32G431KBTx**.

## Functional block diagram
 
> [!NOTE]
> Diagram to be added in a *very near* future...

## Component Details
 
| Block             | Component                              | Role                                                |
|-------------------|-----------------------------------------|------------------------------------------------------|
| Microcontroller   | **STM32G431KB** (Cortex-M4F)            | Main processing: GPIO, ADC, I2C, SPI, UART          |
| Display           | **epd1in54_V2** e-paper, `200×200 px`   | Main UI: time, menus, measurement screens           |
| Heart-rate sensor | **HW827**                               | Optical PPG sensor (~525 nm green LED), analog output |
| Motion sensor     | **MPU6050**                             | 6-axis accelerometer/gyroscope, used for step counting |
| Connectivity      | **HC-05**                               | Bluetooth-to-UART bridge to the companion Android app |
| User input        | Rotary encoder (2-phase quadrature)     | Menu navigation (rotate left / right)                 |
| User input        | Push button ×1 (central)                | Menu select / confirm                                 |
 
> [!NOTE]
> What the firmware calls the "left" and "right" buttons (`BTN_GAUCHE`, `BTN_DROIT`) are **not**
> two separate pushbuttons. They are the two quadrature phases of a single rotary encoder. Only
> the **central** button is an actual independent pushbutton. See [HMI documentation](./hmi.md) for the
> decoding logic.

## Pin Mapping
 
| Component                | Pin                | STM32G431KB GPIO | Interface          |
|---------------------------|---------------------|------------------|---------------------|
| **HW827** (pulse sensor) | analog out          | `PA0` (`ADC1_IN1`) | ADC                 |
| Debug console            | `TX`                | `PA2`            | UART2               |
| Debug console            | `RX`                | `PA3`            | UART2               |
| **epd1in54_V2**          | `CS`                | `PA4`            | SPI1                |
| **epd1in54_V2**          | `SCK`               | `PA5`            | SPI1                |
| **epd1in54_V2**          | `MOSI`              | `PA7`            | SPI1                |
| **epd1in54_V2**          | `DC`                | `PA8`            | GPIO                |
| **HC-05** (Bluetooth)    | `TX`                | `PA9`            | UART1               |
| **HC-05** (Bluetooth)    | `RX`                | `PA10`           | UART1               |
| Central button            | –                   | `PA11`           | GPIO (input, pull-down) |
| Rotary encoder            | Phase A ("left")    | `PA12`           | GPIO / EXTI (pull-up) |
| **MPU6050**               | `SCL`               | `PA15`           | I2C1                |
| **epd1in54_V2**          | `BUSY`              | `PB0`            | GPIO (input)        |
| **epd1in54_V2**          | `RST`               | `PB3`            | GPIO (output)       |
| Rotary encoder            | Phase B ("right")   | `PB5`            | GPIO / EXTI (pull-up) |
| **MPU6050**               | `SDA`               | `PB7`            | I2C1                |
 
> [!NOTE]
> The e-paper SPI bus has no MISO line. The `epd1in54_V2` only ever receives data (frame buffer
> and commands); it never talks back to the MCU over SPI. `BUSY` is the only signal flowing the
> other way, and it's a plain GPIO read, not part of the SPI peripheral itself.

## Software Peripheral Configuration
 
All of the above is mirrored at firmware level in `config.h`, which acts as a single switchboard
enabling or disabling every BSP module used in the project:
 
```c
#define USE_BSP_TIMER   1   // Timer 4, used for periodic step-detection polling
#define USE_BSP_EXTIT   1   // External interrupts, used for the rotary encoder
#define USE_RTC         1   // Real-time clock, used for the watch face
 
#define USE_ADC         1
#define USE_IN1         1   // PA0; HW827 pulse sensor
 
#define USE_EPAPER      1   // epd1in54_V2, drives USE_SPI automatically
#define USE_MPU6050     1   // Accelerometer/gyroscope, drives USE_I2C automatically
```
 
Two UARTs are configured independently for two completely different purposes:
 
- **UART1** (`PA9`/`PA10`) is dedicated to the **HC-05** Bluetooth module — see
  [Connectivity documentation](./connectivity.md).
- **UART2** (`PA2`/`PA3`) is the debug console (`115200` baud), redirected to `printf()` via
  `BSP_SYS_set_std_usart()` in `main.c`. Every `printf()` call in the firmware, such as state machine
  transitions, sensor init status and error messages, ends up here.
