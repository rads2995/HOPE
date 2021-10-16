# Define minimum required version for CMake
cmake_minimum_required(VERSION 3.21)

# Details of the project
project(HOPE VERSION 1.0
        DESCRIPTION "Aerospace Trajectory Simulations"
        LANGUAGES CXX)

# Set binary to output at root directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# The compiled library code resides here
add_subdirectory(src)
