# 💓 Heart-Rate Measurement
 
## A pulse's journey through the system
 
```
HW827 (analog PPG) ➜ ADC1_IN1 @ ~71.43 Hz, 1 sample / 14 ms ➜ Raw buffer (740 samples, ~10.36 s) ➜ Float conversion ➜ Band-pass filter (moving-average low-pass + subtraction high-pass) ➜ Adaptive threshold (0.1 × std) ➜ Peak detection (≥ 0.4 s apart) ➜ BPM averaging
```
 
The whole pipeline lives in `heartbeat.c`, and unlike the accelerometer pipeline (see [Step Counter documentation](./stepcounter.md)), it runs as a single **blocking** sequence rather than a background interrupt: the user presses the heart-rate menu entry, the watch freezes on a loading screen for about ten seconds while it samples and crunches the signal, then shows a BPM value.

## Hardware: the HW827 sensor
 
> ### What is photoplethysmography (PPG)?
> PPG is an optical method for measuring blood volume changes at the skin's surface. A green LED
> (~525 nm) shines into the skin, and a photodiode measures how much of that light gets reflected
> back. Blood absorbs green light more than surrounding tissue does, so each heartbeat, which
> pushes a small pulse of blood through the capillaries, shows up as a tiny dip in the reflected
> light, repeating at the heart rate.

The **HW827** outputs this measurement as a single analog voltage, read directly by the **STM32G431KB**'s internal ADC on `PA0` (`ADC1_IN1`, see [Architecture documentation](./architecture.md#pin-mapping)). A sensor like this is a convenient match for a single-MCU design: no I2C/SPI driver, no register configuration, just one ADC channel to sample.

## Acquisition
 
### Sampling parameters
 
| Parameter           | Value                          |
|----------------------|---------------------------------|
| Sample interval      | `14 ms` (`HW827_SAMPLE_TIME`)  |
| Sampling rate (`FS`)  | `1000 / 14 ≈ 71.43 Hz`          |
| Samples per recording | `740` (`HW827_RECORDING_SIZE`) |
| Recording duration   | `740 × 14 ms ≈ 10.36 s`          |
| ADC channel          | `ADC1`, `ADC1_IN1` (`PA0`)       |
| Acquisition mode     | Blocking, one `HAL_Delay()` per sample |

### `HW827_Recording_Process_1ms()`
 
Despite its name (a holdover from an originally interrupt-driven, millisecond-tick design), this function is fully blocking: it loops `740` times, reading one ADC sample and sleeping `14 ms` on every iteration, for a total of ~10.36 seconds with the CPU unavailable for anything else.

```c
while (hw827_index < HW827_RECORDING_SIZE) {
    hw827_data[hw827_index++] = BSP_ADC_getValue(ADC_1);
    printf("#");                  // progress indicator
    HAL_Delay(HW827_SAMPLE_TIME); // 14 ms
}
```

When `HW827_TEST_MODE` is enabled (it is, by default; see `heartbeat.h`), the `#` characters printed on every sample give a simple `[#####...#####]` progress bar on the debug console for the full duration of the recording.

### CSV export: `HW827_Recording_PrintCSV()`
 
The raw buffer can be dumped over the debug UART as a MATLAB compatible array (`bat = [...]`). This is exactly the format consumed by the project's MATLAB validation script (see below). Recorded data can be pasted straight from the serial console into MATLAB without any reformatting.

## From MATLAB prototype to embedded C
 
Before being ported to C, the filtering and peak-detection logic was first developed and validated in MATLAB on real recorded PPG traces. That prototype used a proper 3rd-order **Butterworth** band-pass filter (`0.5–5 Hz`, applied bidirectionally with `filtfilt` to avoid phase distortion), an adaptive threshold of `mean + 0.5 × std`, and a `0.4 s` minimum peak distance. On one recorded sample, it measured a mean heart rate of `103.0 bpm` (min `42.9`, max `112.8`).
 
The embedded version keeps the same overall shape: filter, adaptive threshold, peak detection, BPM from inter-peak intervals, but trades the Butterworth IIR filter for something much cheaper to run on a microcontroller without a DSP/filter library: a moving-average low-pass followed by subtraction. See [Step Counter documentation](./stepcounter.md) for the equivalent trade-off made on the accelerometer side.

## Signal Pre-Processing
 
### Band-pass filter: `bandpass_filter_ppg()`
 
The filter runs in two conceptual steps, both folded into a single pass over the data:
 
1. **Low-pass**: A 5-point moving average, giving a cutoff around `FS / 5 ≈ 14.28 Hz`.
2. **High-pass**: The moving average is subtracted from the original signal, removing the slow
   baseline drift (motion, ambient light changes) while keeping faster pulsatile variations.

### Adaptive threshold
 
Before peak detection, `calcule_bpm()` computes the mean and standard deviation of the filtered
signal, then derives a threshold from it:
 
| Mode                          | Threshold formula              |
|--------------------------------|----------------------------------|
| Normal (`HW827_BYPASS_FILTER = 0`) | `0.1 × std(filtered)`         |
| Bypass (`HW827_BYPASS_FILTER = 1`) | `max(0.1 × std(raw), 50.0)`   |
 
The bypass mode skips `bandpass_filter_ppg()` entirely and runs peak detection directly on the raw ADC samples, with a hard floor of `50` on the threshold to compensate for not having removed the DC bias. It exists as a debug/comparison switch, toggled by hand in `heartbeat.h` rather than at runtime.

## Peak Detection: `find_peaks()`
 
A sample is counted as a heartbeat if it satisfies three conditions:
 
1. It's above the adaptive `threshold`.
2. It's a local maximum (`signal[i] > signal[i-1]` and `signal[i] > signal[i+1]`).
3. It's at least `min_dist` samples away from the previously accepted peak.

| Parameter             | Value                              |
|------------------------|--------------------------------------|
| `MIN_PEAK_DIST_SEC`    | `0.4 s`                              |
| `MIN_PEAK_DIST_SAMPLES`| `(uint16_t)(FS × 0.4) ≈ 28 samples`  |
 
That `0.4 s` minimum spacing between two accepted beats also sets an implicit ceiling on what the algorithm can ever report: `60 / 0.4 = 150 bpm` maximum, regardless of what the sensor sees.

## BPM Calculation: `calcule_bpm()`
 
Once peaks are found, the BPM is the average of the instantaneous rate across every consecutive pair of detected peaks:
 
```c
float dt = (peak_locs[i] - peak_locs[i - 1]) * HW827_SAMPLE_PERIODE; // seconds
float bpm_inst = 60.0f / dt;
```

`*bpm_moy` is the mean of all `bpm_inst` values, and is reported as `0` if fewer than 2 peaks were found (one peak alone gives no interval to measure).
 
`calcule_bpm()` also prints a detailed trace to the debug console on every run: a handful of filtered sample values, the computed mean/std/threshold, how many samples exceeded the threshold, every detected peak-to-peak interval with its instantaneous BPM, and the final result.
