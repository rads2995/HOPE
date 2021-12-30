// integrator.hpp: header file for numerical integration functions 
#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP

// Include Eigen::Matrix typed from system.hpp header file
#include <system.hpp>

// Include Boost's odeint library, an ODE numerical integrator
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Include standard libraries
#include <fstream>

// Declare and define files to write system's solution and state outputs  
extern std::ofstream states("states_result.txt");
extern std::ofstream output("output_result.txt");

// Declare state-space system integration functions
template<typename T> void state_system(double m_t0, double m_tf, double m_step_size);
template<typename T> void state_function (const T &x, T &dxdt, double t);
template<typename T> void write_states (const T &x, const double t);
template<typename T> void write_output (const T &y);

// Declare nonlinear system integration functions
void nonlinear_system(double m_t0, double m_tf, double m_step_size);
void nonlinear_function(const function_type &x, function_type &dxdt, double t);
void write_nonlinear_results(const function_type &x, const double t);

// Define integrator.hpp state-space integration template functions
template<typename T> void state_system(double m_t0, double m_tf, double m_step_size) {
    boost::numeric::odeint::runge_kutta_dopri5<T, double, T, double, boost::numeric::odeint::vector_space_algebra> stepper;
    boost::numeric::odeint::integrate_const(stepper, state_function<T>, x0, m_t0, m_tf, m_step_size, write_states<T>);
}

template<typename T> void state_function (const T &x, T &dxdt, double t) {
    dxdt = A * x + B * u;
    y = C * x + D * u;
    write_output<T>(y);
}

template<typename T> void write_states (const T &x, const double t) {
    states << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        states << x[i] << '\t';
    
    states << std::endl; 
}

template<typename T> void write_output (const T &y) {
    for (size_t i = 0; i < y.rows(); i++)
        output << y(i) << '\t';
    
    output << std::endl; 
}

#endif // INTEGRATOR_HPP
