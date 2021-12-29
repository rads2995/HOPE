// matrix.hpp: header file for eigen type funtions and variables
#ifndef MATRIX_HPP
#define MATRIX_HPP

// Include Eigen, a C++ template library for linear algebra 
#include <Eigen/Core>

// Declare data type for dynamic-size matrices of type double
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> state_type;

// Define global matrices and vectors of type eigen-dynamic
extern state_type A;
extern state_type B;
extern state_type C;
extern state_type D;
extern state_type u;
extern state_type y;
extern state_type x0;

#endif // MATRIX_HPP
