#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP

// Include Eigen, a C++ template library for linear algebra 
#include <Eigen/Core>

// Include Boost's library ODE numerical integrator
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Define data type for dynamic-size matrices 
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> state_type;

// Define global matrices and vectors
extern state_type A, B, C, D, u, x0, y;

// Define template state-space system function 
template<typename T> 
void state_function (const T &x, T &dxdt, double t);

// Define template function to write state solutions
template<typename T> 
void write_states (const T &x, const double t);

// Define template function to write output solutions
void write_output (const state_type &y);

// Function definition to simulate system based on number of states
template<typename T> 
void simulate_system(double t0, double tf, double step_size);

#endif // INTEGRATOR_HPP
