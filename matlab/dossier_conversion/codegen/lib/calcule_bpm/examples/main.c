#include "main.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

#define N 256
#define FS 40.0f
#define THRESHOLD 400.0f

// ---------- Fonctions prototypes ----------
void compute_acc_norm(const float *accX, const float *accY, const float *accZ, float *accNorm, uint16_t len);
void bandpass_filter(const float *signal, float *filtered, uint16_t len);
uint16_t detect_steps(const float *signal, uint16_t len, float threshold);
uint16_t calcule_pas(const float *accX, const float *accY, const float *accZ, uint16_t len);

// ---------- MAIN -------

uint16_t pas = calcule_pas(accX, accY, accZ, N);


void compute_acc_norm(const float *accX, const float *accY, const float *accZ, float *accNorm, uint16_t len) {
    for (uint16_t i = 0; i < len; i++) {
        accNorm[i] = sqrtf(accX[i]*accX[i] + accY[i]*accY[i] + accZ[i]*accZ[i]);
    }
}

void bandpass_filter(const float *signal, float *filtered, uint16_t len) {
    // Coefficients Butterworth ordre 2, bande [0.5 - 3] Hz, fs=40Hz
    float a1 = -1.7786f, a2 = 0.8008f;
    float b0 = 0.0675f, b1 = 0.0f, b2 = -0.0675f;

    float x1 = 0.0f, x2 = 0.0f;
    float y1 = 0.0f, y2 = 0.0f;

    for (uint16_t i = 0; i < len; i++) {
        float x0 = signal[i];
        float y0 = b0 * x0 + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;

        filtered[i] = y0;

        x2 = x1; x1 = x0;
        y2 = y1; y1 = y0;
    }
}

uint16_t detect_steps(const float *signal, uint16_t len, float threshold) {
    uint16_t count = 0;
    for (uint16_t i = 1; i < len - 1; i++) {
        if (signal[i] > threshold && signal[i] > signal[i-1] && signal[i] > signal[i+1]) {
            count++;
            i += 5; // saut pour éviter détection multiple------------------------------------------------------------------------------------------<
        }
    }
    return count;
}

uint16_t calcule_pas(const float *accX, const float *accY, const float *accZ, uint16_t len) {
    float accNorm[N];
    float filtered[N];

    compute_acc_norm(accX, accY, accZ, accNorm, len);
    bandpass_filter(accNorm, filtered, len);

    float mean = 0.0f;
    for (uint16_t i = 0; i < len; i++) mean += filtered[i];
    mean /= (float)len;

    for (uint16_t i = 0; i < len; i++) filtered[i] -= mean;

    return detect_steps(filtered, len, THRESHOLD);
}
















#include "main.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define N 256
#define FS 60.0f
#define MIN_PEAK_DIST_SEC 0.4f
#define MIN_PEAK_DIST_SAMPLES ((uint16_t)(FS * MIN_PEAK_DIST_SEC))

extern UART_HandleTypeDef huart2;

// --- Fonctions ---
void bandpass_filter_ppg(const float *input, float *output, uint16_t len);
uint16_t find_peaks(const float *signal, uint16_t len, float threshold, uint16_t min_dist, float *peak_locs);
void calcule_bpm(const float *bat, float periode, uint16_t len, uint16_t *nb_battements, float *bpm_moy);
void UART_Print(const char *msg);

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_USART2_UART_Init();

    float periode = 1.0f / FS;
    float bat[N];

    // 🧪 Simule un signal cardiaque à ~1.2 Hz (72 BPM)
    for (uint16_t i = 0; i < N; i++) {
        float t = i * periode;
        bat[i] = 2048.0f + 500.0f * sinf(2.0f * M_PI * 1.2f * t);
    }

    uint16_t nb_battements = 0;
    float bpm_moy = 0.0f;

    calcule_bpm(bat, periode, N, &nb_battements, &bpm_moy);

    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Battements: %u | BPM: %.2f\r\n", nb_battements, bpm_moy);
    UART_Print(buffer);

    while (1) {
        HAL_Delay(1000);
    }
}




void bandpass_filter_ppg(const float *input, float *output, uint16_t len) {
    // Coeffs obtenus depuis MATLAB butter(3,[0.5 5]/(60/2))
    float a[4] = {1.0f, -5.244f, 10.764f, -8.788f};
    float b[4] = {0.0004f, 0.0012f, 0.0012f, 0.0004f};

    float x1 = 0, x2 = 0, x3 = 0;
    float y1 = 0, y2 = 0, y3 = 0;

    for (uint16_t i = 0; i < len; i++) {
        float x0 = input[i];
        float y0 = b[0]*x0 + b[1]*x1 + b[2]*x2 + b[3]*x3
                   - a[1]*y1 - a[2]*y2 - a[3]*y3;

        output[i] = y0;

        x3 = x2; x2 = x1; x1 = x0;
        y3 = y2; y2 = y1; y1 = y0;
    }
}

uint16_t find_peaks(const float *signal, uint16_t len, float threshold, uint16_t min_dist, float *peak_locs) {
    uint16_t count = 0;
    uint16_t last_peak = 0;

    for (uint16_t i = 1; i < len - 1; i++) {
        if (signal[i] > threshold &&
            signal[i] > signal[i - 1] &&
            signal[i] > signal[i + 1]) {

            if (count == 0 || (i - last_peak) >= min_dist) {
                peak_locs[count++] = i;
                last_peak = i;
            }
        }
    }
    return count;
}



void calcule_bpm(const float *bat, float periode, uint16_t len, uint16_t *nb_battements, float *bpm_moy) {
    float filtered[N];
    bandpass_filter_ppg(bat, filtered, len);

    // Moyenne et écart-type
    float mean = 0, std = 0;
    for (uint16_t i = 0; i < len; i++) mean += filtered[i];
    mean /= len;
    for (uint16_t i = 0; i < len; i++) std += (filtered[i] - mean) * (filtered[i] - mean);
    std = sqrtf(std / len);

    float seuil = mean + 0.5f * std;
    float peak_locs[N];
    uint16_t nb = find_peaks(filtered, len, seuil, MIN_PEAK_DIST_SAMPLES, peak_locs);

    float bpm_sum = 0;
    for (uint16_t i = 1; i < nb; i++) {
        float dt = (peak_locs[i] - peak_locs[i - 1]) * periode;
        if (dt > 0) bpm_sum += 60.0f / dt;
    }

    *nb_battements = nb;
    *bpm_moy = (nb > 1) ? (bpm_sum / (nb - 1)) : 0.0f;
}
 

















package fr.couiz.question;

public enum CathtgorieQuestion {
    CINEMA,
    HISTOIRE,
    INTERNET,
    TV,
    MATHS,
    CULTUREG,
    MUSIQUE
}

package fr.couiz.question;

public enum Type {
    QMC,
    QPR,
    IMAGE
}