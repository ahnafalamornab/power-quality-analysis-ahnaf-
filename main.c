#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"
#include "io.h"

int main() {
    int count = 0;

    WaveformSample *samples = load_csv("power_quality_log.csv", &count);

    if (samples == NULL) {
        printf("Failed to load CSV file.\n");
        return 1;
    }

    printf("CSV loaded successfully!\n");
    printf("Number of rows: %d\n", count);

    double rms_A = compute_rms(samples, count, 'A');
    double rms_B = compute_rms(samples, count, 'B');
    double rms_C = compute_rms(samples, count, 'C');

    printf("RMS Phase A: %.2f\n", rms_A);
    printf("RMS Phase B: %.2f\n", rms_B);
    printf("RMS Phase C: %.2f\n", rms_C);

    int comp_A = check_compliance(rms_A);
    int comp_B = check_compliance(rms_B);
    int comp_C = check_compliance(rms_C);

    printf("Compliance Phase A: %s\n", comp_A ? "PASS" : "FAIL");
    printf("Compliance Phase B: %s\n", comp_B ? "PASS" : "FAIL");
    printf("Compliance Phase C: %s\n", comp_C ? "PASS" : "FAIL");

    double p2p_A = compute_peak_to_peak(samples, count, 'A');
    double p2p_B = compute_peak_to_peak(samples, count, 'B');
    double p2p_C = compute_peak_to_peak(samples, count, 'C');

    double dc_A = compute_dc_offset(samples, count, 'A');
    double dc_B = compute_dc_offset(samples, count, 'B');
    double dc_C = compute_dc_offset(samples, count, 'C');

    printf("DC Offset Phase A: %.2f\n", dc_A);
    printf("DC Offset Phase B: %.2f\n", dc_B);
    printf("DC Offset Phase C: %.2f\n", dc_C);

    int clip_A = count_clipped(samples, count, 'A', 324.9);
    int clip_B = count_clipped(samples, count, 'B', 324.9);
    int clip_C = count_clipped(samples, count, 'C', 324.9);

    printf("Clipped samples Phase A: %d\n", clip_A);
    printf("Clipped samples Phase B: %d\n", clip_B);
    printf("Clipped samples Phase C: %d\n", clip_C);

    printf("Peak-to-Peak Phase A: %.2f\n", p2p_A);
    printf("Peak-to-Peak Phase B: %.2f\n", p2p_B);
    printf("Peak-to-Peak Phase C: %.2f\n", p2p_C);

    export_results("results.txt", rms_A, rms_B, rms_C, p2p_A, p2p_B, p2p_C, dc_A, dc_B, dc_C);

    free(samples);

    return 0;
}
