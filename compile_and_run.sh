#!/bin/sh

clear
mkdir -p build
cmake -S . -B build/
cd build
make
./HOPE
