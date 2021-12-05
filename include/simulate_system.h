// simulate_system.h: header file containing various functions
#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

// Include necessary Standard Library headers
#include <iostream>
#include <fstream>

// Include Eigen, a C++ template library for linear algebra 
// Info: https://eigen.tuxfamily.org/ 
#include <Eigen/Core>

// Include Boost Library's odeint, an ordinary differential equation numerical integrator
// Info: https://www.boost.org/doc/libs/1_54_0/libs/numeric/odeint/doc/html/index.html
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Define data type for dynamic-size matrices 
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> state_type;

// Define template state-space system function 
template<typename T> void state_function (const T &x, T &dxdt, double t);
// Define template function to write state solutions
template<typename T> void write_states (const T &x, const double t);
// Define template function to write output solutions
template<typename T> void write_output (const T &y);

// Function definition to simulate system based on number of states
template<typename T> void simulate_system(double t0, double tf, double step_size);

#endif // SIMULATE_SYSTEM_H
