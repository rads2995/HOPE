#!/bin/sh

clear
echo "Starting dynamical system simulation..."
echo "Creating build directory..."
mkdir -p build
echo "Generating CMake files for build directory..."
cmake -S . -B build/
echo "Switching to build directory..."
cd build
echo "Compiling project using generated Makefile..."
make
echo "Running executable..."
#./HOPE
echo "Copying results from simulation into Python directory..."
#cp simulation_result.txt ../python/
echo "Switching to Python directory"
cd ../python/
echo "Running python script"
#python plot.py
echo "Plot of resulting simulation has been generated..."
echo "Simulation completed!"
