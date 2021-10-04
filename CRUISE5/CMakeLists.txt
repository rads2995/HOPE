# Define minimum required version for CMake
cmake_minimum_required(VERSION 3.20.6...3.21.3)

project(FitMacro VERSION 1.0
        DESCRIPTION "Macronutrient calculator"
        LANGUAGES CXX)

# The compiled library code resides here
add_subdirectory(src)

# The executable code resides here
add_subdirectory(app)

# The data to be included at runtime is here
add_subdirectory(data)
