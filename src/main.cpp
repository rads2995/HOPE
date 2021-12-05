// main.cpp: source file containing main function
#include "simulate_system.h"

using namespace boost::numeric::odeint;

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
    dxdt = A * x + B * u;
    // y = C * x + D * u;
}

// Write the system's states into the text file
template<typename T>
void write_states (const T &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}

// TODO: function to resize matrices passed from reference

void two_states_system(double t0, double tf, double step_size)
{
    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    runge_kutta_dopri5<Eigen::Matrix<double, 2, 1>, double, Eigen::Matrix<double, 2, 1>, double, vector_space_algebra> stepper;
    
    integrate_const(stepper, state_function<Eigen::Matrix<double, 2, 1>>, x0, t0, tf, step_size, write_states<Eigen::Matrix<double, 2, 1>>);
}

int main() 
{  
    double t0 {0}, tf {5}, step_size {0.01};
    
    two_states_system(t0, tf, step_size); 
    return (0);
} 
