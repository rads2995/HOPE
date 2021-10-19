#!/bin/sh

echo "Building simulation project..."
echo "Creating build directory..."
mkdir build
echo "Generating CMake files on build directory..."
cmake -S . -B build/
echo "Switching to build directory..."
cd build
echo "Compiling project using Makefile..."
make
echo "Running executable..."
./Simulate
echo "Copying simulation results to python directory..."
cp simulation.txt ../python/
echo "Switching to Python directory..."
cd ../python/
echo "Running Python script to generate plot..."
python *.py
echo "Displaying resultant plot from simulation..."
feh *.png
