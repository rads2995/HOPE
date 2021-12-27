#ifndef MATRIX_HPP
#define MATRIX_HPP

// Include Eigen, a C++ template library for linear algebra 
#include <Eigen/Core>

// Define data type for dynamic-size matrices 
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> state_type;

// Define global matrices and vectors
extern state_type A, B, C, D, u, x0, y;

#endif // MATRIX_HPP
