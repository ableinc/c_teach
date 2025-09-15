#!/bin/bash
# Build the shared library
gcc -c -fPIC calculator.c -o calc.o
gcc -shared -o libcalc.so calc.o
# Tell the system to look for shared libraries in the current directory
export LD_LIBRARY_PATH=.