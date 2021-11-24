#!/bin/sh

clear
echo "Compile simulation project..."
echo "Creating build directory..."
mkdir -p build
echo "Generating CMake files for build directory..."
cmake -S . -B build/
echo "Switching to build directory..."
cd build
echo "Compiling project using Makefile..."
make
echo "Running executable..."
./HOPE
echo "Copy results into Python directory"
cp simulation_result.txt ../python/
