// system.hpp: header file for eigen type funtions and variables
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

// Include Eigen, a C++ template library for linear algebra 
#include <Eigen/Core>

// Declare data type for dynamic-size matrices of type double
using state_type = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>;
using function_type = Eigen::Matrix<double, 3, 1>;

// Define global matrices and vectors of type eigen-dynamic
extern state_type A, B, C, D, u, y, x0;

#endif // SYSTEM_HPP
