#!/bin/bash
# Build the shared library
gcc -c -fPIC calculator.c -o calculator.o
gcc -shared -o libcalc.so calculator.o
export LD_LIBRARY_PATH=.