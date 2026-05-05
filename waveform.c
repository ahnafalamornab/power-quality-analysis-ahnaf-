
 Created by Ahnaf on 28/04/2026.


#include <math.h>
#include "waveform.h"

double get_phase_voltage(const WaveformSample *sample, char phase) {
    if (phase == 'A') {
        return sample->phase_A_voltage;
    }
    if (phase == 'B') {
        return sample->phase_B_voltage;
    }
    return sample->phase_C_voltage;
}

double compute_rms(const WaveformSample *samples, int count, char phase) {
    double sum_sq = 0.0;

    for (int i = 0; i < count; i++) {
        double voltage = get_phase_voltage(&samples[i], phase);
        sum_sq += voltage * voltage;
    }

    return sqrt(sum_sq / count);
}

double compute_peak_to_peak(const WaveformSample *samples, int count, char phase) {
    double min = get_phase_voltage(&samples[0], phase);
    double max = get_phase_voltage(&samples[0], phase);

    for (int i = 1; i < count; i++) {
        double voltage = get_phase_voltage(&samples[i], phase);

        if (voltage < min) min = voltage;
        if (voltage > max) max = voltage;
    }

    return max - min;
}

double compute_dc_offset(const WaveformSample *samples, int count, char phase) {
    double sum = 0.0;

    for (int i = 0; i < count; i++) {
        sum += get_phase_voltage(&samples[i], phase);
    }

    return sum / count;
}

int count_clipped(const WaveformSample *samples, int count, char phase, double limit) {
    int clipped = 0;

    for (int i = 0; i < count; i++) {
        double voltage = get_phase_voltage(&samples[i], phase);

        if (fabs(voltage) >= limit) {
            clipped++;
        }
    }

    return clipped;
}

int check_compliance(double rms) {
    if (rms >= 207.0 && rms <= 253.0) {
        return 1;
    }
    return 0;
}
