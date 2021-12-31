// system.hpp: header file for array and matrix types declarations
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

// Include Boost's odeint library, an ODE numerical integrator
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Include Eigen, a C++ template library for linear algebra 
#include <Eigen/Core>

// Include standard libraries
#include <fstream>

// Define type alias for dynamic-size matrices of type double
using matrix_type = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>;

// Define type alias for fixed-size array of type double 
using array_type = std::array<double, 3>;

// Declare global dynamic matrices and vectors of type double
extern matrix_type A, B, C, D, u, y, x0;

#endif // SYSTEM_HPP
