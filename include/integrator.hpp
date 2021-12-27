#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP

#include <matrix.hpp>

// Include Boost's odeint library, an ODE numerical integrator
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Include standard libraries
#include <fstream>

// Define data files to write system's states and output from simulation  
std::ofstream data("simulation_result.txt");
std::ofstream output("output_result.txt");

template<typename T> 
void simulate_system(double m_t0, double m_tf, double m_step_size);

template<typename T> 
void state_function (const T &x, T &dxdt, double t);

template<typename T> 
void write_states (const T &x, const double t);

void write_output (const state_type &y);

#endif // INTEGRATOR_HPP
