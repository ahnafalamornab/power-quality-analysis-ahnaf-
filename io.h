


#ifndef POWER_QUALITY_ANALYSER_IO_H
#define POWER_QUALITY_ANALYSER_IO_H

#include "waveform.h"

WaveformSample *load_csv(const char *filename, int *count);
void export_results(const char *filename, double rmsA, double rmsB, double rmsC,
                    double p2pA, double p2pB, double p2pC,
                    double dcA, double dcB, double dcC);
#endif //POWER_QUALITY_ANALYSER_IO_H
