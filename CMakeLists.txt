cmake_minimum_required(VERSION 3.20)
project(Power_Quality_Analyser C)

set(CMAKE_C_STANDARD 99)

add_executable(Power_Quality_Analyser main.c
        main.c
        io.c
        waveform.c )


