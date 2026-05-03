//
// Created by Ahnaf on 28/04/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "io.h"

WaveformSample *load_csv(const char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[512];

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return NULL;
    }

    int rows = 0;
    while (fgets(line, sizeof(line), file)) {
        rows++;
    }

    if (rows == 0) {
        fclose(file);
        return NULL;
    }

    WaveformSample *samples = malloc(rows * sizeof(WaveformSample));
    if (samples == NULL) {
        fclose(file);
        return NULL;
    }

    rewind(file);
    // Skip header again
    fgets(line, sizeof(line), file);

    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL && i < rows) {
        sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
               &samples[i].timestamp,
               &samples[i].phase_A_voltage,
               &samples[i].phase_B_voltage,
               &samples[i].phase_C_voltage,
               &samples[i].line_current,
               &samples[i].frequency,
               &samples[i].power_factor,
               &samples[i].thd_percent);
        i++;
    }

    fclose(file);
    *count = rows;
    return samples;
}
void export_results(const char *filename, double rmsA, double rmsB, double rmsC,
                    double p2pA, double p2pB, double p2pC,
                    double dcA, double dcB, double dcC) {
    FILE *file = fopen(filename, "w"); // "w" মানে হলো write মোড
    if (file == NULL) {
        printf("Error: Could not create results file.\n");
        return;
    }

    fprintf(file, "--- Power Quality Analysis Report ---\n\n");

    fprintf(file, "RMS Voltage:\n");
    fprintf(file, "Phase A: %.2f V\nPhase B: %.2f V\nPhase C: %.2f V\n\n", rmsA, rmsB, rmsC);

    fprintf(file, "Peak-to-Peak Amplitude:\n");
    fprintf(file, "Phase A: %.2f V\nPhase B: %.2f V\nPhase C: %.2f V\n\n", p2pA, p2pB, p2pC);

    fprintf(file, "DC Offset:\n");
    fprintf(file, "Phase A: %.2f V\nPhase B: %.2f V\nPhase C: %.2f V\n", dcA, dcB, dcC);

    fclose(file);
    printf("Results successfully exported to %s\n", filename);
}