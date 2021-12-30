# Define minimum required version for CMake
cmake_minimum_required(VERSION 3.22)

# Details of the project
project(HOPE LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add external libraries and required dependencies
add_library (extern_libs src/integrator.cpp)
target_include_directories(extern_libs PUBLIC 
        include
        libs/eigen
        libs/odeint/include 
        libs/config/include 
        libs/utility/include 
        libs/core/include 
        libs/type_traits/include
        libs/fusion/include
        libs/mpl/include
        libs/preprocessor/include
        libs/static_assert/include
        libs/range/include
        libs/iterator/include
        libs/concept_check/include
        libs/assert/include
        libs/detail/include
        libs/function_types/include
        libs/array/include
        libs/throw_exception/include
        libs/units/include
        libs/typeof/include
        libs/integer/include
        libs/ublas/include
        libs/serialization/include)

# Add source executable and link to libraries
add_executable(HOPE src/main.cpp)
target_link_libraries(HOPE PRIVATE extern_libs)
