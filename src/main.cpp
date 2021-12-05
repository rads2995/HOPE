// main.cpp: source file containing main function
#include "simulate_system.h"

// Define global matrices and vectors 
state_type A = state_type::Zero(2, 2);
state_type B = state_type::Zero(2, 2);
state_type C = state_type::Zero(2, 2);
state_type D = state_type::Zero(2, 2);
state_type u = state_type::Zero(2, 1);
state_type x0 = state_type::Zero(2, 1);

template<typename T>
void state_function (const T &x, T &dxdt, double t)
{
    dxdt = A * x;
}

// Write the system's states into the text file
void write_states (const Eigen::Matrix<double, Eigen::Dynamic, 1> &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}

void two_states_system()
{
    double t0 = 0;
    double tf = 10;
    double step_size = 0.01;
    
    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    boost::numeric::odeint::runge_kutta_dopri5<Eigen::Matrix<double, 2, 1>, double, Eigen::Matrix<double, 2, 1>, double, boost::numeric::odeint::vector_space_algebra> stepper;
    
    boost::numeric::odeint::integrate_const(stepper, state_function<Eigen::Matrix<double, 2, 1>>, x0, t0, tf, step_size, write_states);
}

int main() 
{  
    two_states_system(); 
    return (0);
} 
