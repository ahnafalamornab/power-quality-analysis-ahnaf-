Power Quality Waveform Analyser
This repository contains a C program created for the Programming for Engineers UGMFGT 15 1 coursework at the University of the West of England, UWE Bristol. The project focuses on analysing voltage waveform data taken from industrial power supply monitoring equipment.
The program works by reading recorded sensor log files and processing the data sample by sample. It performs basic power quality calculations, looks for common issues in the supply, and presents the results as a clear text based report that can be easily reviewed.
The analyser is capable of loading CSV formatted input files and calculating RMS voltage, peak to peak voltage, and DC offset. It also checks for waveform clipping when voltage levels exceed expected limits. Dynamic memory allocation is used so the program can work with different file sizes without relying on fixed length arrays.
To build and run the program, a C99 compatible compiler and CMake are required. Development was carried out using CLion, but the program can be compiled using any IDE or toolchain that supports C.
Repository information:
Student name: Ahnaf Ornab.
UWE ID: a2 ornab.
Module: UGMFGT 15 1 Programming for Engineers.
University: University of the West of England, UWE Bristol.
GitHub repository:https://github.com/ahnafalamornab/power-quality-analysis-ahnaf-