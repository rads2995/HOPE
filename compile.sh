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
