# Define minimum required version for CMake
cmake_minimum_required(VERSION 3.22)

# Details of the project
project(HOPE VERSION 1.0
        DESCRIPTION "Simulation of Dynamical Systems"
        LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set binary to output at build directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# The compiled source code resides here
add_subdirectory(src)
