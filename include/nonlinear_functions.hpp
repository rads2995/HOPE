// nonlinear_functions.hpp: 
#ifndef NONLINEAR_FUNCTIONS_HPP
#define NONLINEAR_FUNCTIONS_HPP

#include <system.hpp>

// Declare nonlinear system integration functions
void nonlinear_system(double m_t0, double m_tf, double m_step_size);
void nonlinear_function(const array_type &x, array_type &dxdt, double t);
void write_nonlinear_results(const array_type &x, const double t);

#endif // NONLINEAR_FUNCTIONS_HPP
