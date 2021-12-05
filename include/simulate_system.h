// simulate_system.h: header file containing various functions
#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

// Include necessary libraries from STD
#include <iostream>
#include <fstream>

// Include Eigen, a C++ template library for linear algebra 
// For more info visit https://eigen.tuxfamily.org/ 
#include <Eigen/Core>

// Boost Library's ordinary differential equations numerical solvers
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Write results from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

// Define types for dynamic matrix and dynamic vector 
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> state_type;

template<typename T>
void state_function (const T &x, T &dxdt, double t);

// Write the system's states into the text file
void write_states (const Eigen::Matrix<double, Eigen::Dynamic, 1> &x, const double t);

#endif // SIMULATE_SYSTEM_H
