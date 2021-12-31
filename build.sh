#!/bin/bash
mkdir -p debug
cmake -S . -B debug/
make -C debug/
