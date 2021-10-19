#!/bin/sh

echo "Building project!"
mkdir build
cd ./build
cmake ..
make
echo "Executing project"
./Simulate
echo "Copying simulation results to Python folder"
cp *.txt ../python/
cd ../python/
echo "Executing python script"
python plot.py
echo "Display simulation plot"
feh output.png
