// system.hpp: header file for eigen type funtions and variables
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

// Include Boost's odeint library, an ODE numerical integrator
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Include Eigen, a C++ template library for linear algebra 
#include <Eigen/Core>

// Include standard libraries
#include <fstream>

// Declare data type for dynamic-size matrices of type double
using matrix_type = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>;
using array_type = std::array<double, 3>;

// Define global matrices and vectors of type eigen-dynamic
extern matrix_type A, B, C, D, u, y, x0;

#endif // SYSTEM_HPP
