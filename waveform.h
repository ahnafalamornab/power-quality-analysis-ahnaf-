 Created by Ahnaf on 28/04/2026.

#ifndef POWER_QUALITY_ANALYSER_WAVEFORM_H
#define POWER_QUALITY_ANALYSER_WAVEFORM_H
typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
} WaveformSample;

double get_phase_voltage(const WaveformSample *sample, char phase);
double compute_rms(const WaveformSample *samples, int count, char phase);
double compute_peak_to_peak(const WaveformSample *samples, int count, char phase);
double compute_dc_offset(const WaveformSample *samples, int count, char phase);
int count_clipped(const WaveformSample *samples, int count, char phase, double limit);
int check_compliance(double rms);

#endif 
