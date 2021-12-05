// main.cpp: source file containing main function
#include "simulate_system.h"
#include "matrix_functions.h"

// Write states from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

// Define global matrices 
state_type A, B, C, D, u, x0;

int main() 
{  
    double t0 {0}, tf {5}, step_size {0.01};
    
    simulate_system<Eigen::Matrix<double, 2, 1>>(t0, tf, step_size); 
    return (0);
}

template<typename T>
void simulate_system(double t0, double tf, double step_size)
{
    matrix_resize(A, x0, 2);

    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    boost::numeric::odeint::runge_kutta_dopri5<T, double, T, double, boost::numeric::odeint::vector_space_algebra> stepper;
    boost::numeric::odeint::integrate_const(stepper, state_function<T>, x0, t0, tf, step_size, write_states<T>);
}

// Define template state function for various matrix sizes
template<typename T>
void state_function (const T &x, T &dxdt, double t)
{
    dxdt = A * x;// + B * u;
}

template<typename T>
void write_states (const T &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}
