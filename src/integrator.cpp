#include <integrator.hpp>

#include <fstream>

// Define data files for states and output from simulation  
std::ofstream data("simulation_result.txt");
std::ofstream output("output_result.txt");

template<typename T>
void simulate_system(double t0, double tf, double step_size)
{
    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    boost::numeric::odeint::runge_kutta_dopri5<T, double, T, double, boost::numeric::odeint::vector_space_algebra> stepper;
    boost::numeric::odeint::integrate_const(stepper, state_function<T>, x0, t0, tf, step_size, write_states<T>);
}

template<typename T>
void state_function (const T &x, T &dxdt, double t)
{
    // Solve differential equation of state-space system
    dxdt = A * x + B * u;
    
    // Solve output equation of state-space system
    y = C * x + D * u;

    // Write output equation at current step 
    write_output(y);
}

template<typename T>
void write_states (const T &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}

void write_output (const state_type &y)
{
    for (size_t i = 0; i < y.rows(); i++)
        output << y(i) << '\t';
    
    output << std::endl; 
}
