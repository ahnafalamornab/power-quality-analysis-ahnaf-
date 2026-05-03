Power Quality Waveform Analyser
This repository contains a C based program created for the Programming for Engineers UGMFGT 15 1 coursework at the University of the West of England UWE Bristol. The software is intended to work with voltage waveform data collected from industrial power supply sensors.
The program processes recorded sensor files and carries out standard electrical calculations. It is able to evaluate the quality of the supply by calculating key values and identifying basic compliance issues. Results are presented as a clear text based analysis so they can be easily checked and understood.
Key features of the program include loading and interpreting CSV formatted data files, calculating RMS voltage peak to peak voltage and DC offset, and detecting waveform clipping where voltage limits are exceeded. Memory is allocated dynamically using malloc and released using free so that large datasets can be handled safely and efficiently.
To build and run the program a C99 compatible compiler and CMake are required. Development was carried out using CLion although any C supporting IDE can be used.
Repository information
Student name Ahnaf Ornab
UWE ID- a2-ornab
Module UGMFGT 15 1 Programming for Engineers
University University of the West of England UWE Bristol
GitHub repository https://github.com/Sakib-45/Power_Quality_Analyser
