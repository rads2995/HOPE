#!/bin/bash
mkdir -p build
emcmake cmake -S . -B build/
emmake make -C build/
