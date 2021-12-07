# Define minimum required version for CMake
cmake_minimum_required(VERSION 3.22)

# Details of the project
project(HOPE VERSION 1.1
        DESCRIPTION "Numerical Simulation for LTI State-Space Systems"
        LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set binary to output at build directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# The compiled source code resides here
add_subdirectory(src)

# Copy matrices and vectors from data directory into binary directory
file(COPY ${CMAKE_SOURCE_DIR}/data 
     DESTINATION ${CMAKE_BINARY_DIR})
