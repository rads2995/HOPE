#!/bin/bash
mkdir -p build
cmake -S . -B build/
make -C build/
