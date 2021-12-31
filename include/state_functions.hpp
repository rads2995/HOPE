// state_functions.hpp: header file for state-space integration template functions 
#ifndef STATE_FUNCTIONS_HPP
#define STATE_FUNCTIONS_HPP

// Include dynamic matrix type alias from system header file
#include <system.hpp>

// Declare and define files to write system's solution and state outputs  
std::ofstream states("states_result.txt");
std::ofstream output("output_result.txt");

// Declare state-space system integration template functions
template<typename T> void state_system(double m_t0, double m_tf, double m_step_size);
template<typename T> void state_function (const T &x, T &dxdt, double t);
template<typename T> void write_states (const T &x, const double t);
template<typename T> void write_output (const T &y);

// Define state-space system integration template functions
// state_system: define stepper and perform numerical integration
template<typename T> void state_system(double m_t0, double m_tf, double m_step_size) {
    boost::numeric::odeint::runge_kutta_dopri5<T, double, T, double, boost::numeric::odeint::vector_space_algebra> stepper;
    boost::numeric::odeint::integrate_const(stepper, state_function<T>, x0, m_t0, m_tf, m_step_size, write_states<T>);
}
// state_function: Define the LTI state-space system in the form
//                 {dxdt} = [A] * {x} + [B] * {u}
//                    {y} = [C] * {x} + [D] * {u}  
template<typename T> void state_function (const T &x, T &dxdt, double t) {
    dxdt = A * x + B * u;
       y = C * x + D * u;
    
    // Call the output function to export values of output vector {y}
    write_output<T>(y);
}
// write_states: export the state values at every integration step
template<typename T> void write_states (const T &x, const double t) {
    states << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        states << x[i] << '\t';
    
    states << std::endl; 
}
// write_output: export the output values at every integration step
template<typename T> void write_output (const T &y) {
    for (size_t i = 0; i < y.rows(); i++)
        output << y(i) << '\t';
    
    output << std::endl; 
}

#endif // STATE_FUNCTIONS_HPP
