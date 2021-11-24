#include "simulate_system.h"

#define SIZE 2

using namespace boost::numeric::odeint;

// Write results from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

void ode_function (const Eigen::Matrix<double, SIZE, 1> &x, Eigen::Matrix<double, SIZE, 1> &dxdt, double t);
void write_states (const Eigen::Matrix<double, SIZE, 1> &x, const double t);

Eigen::Matrix<double, SIZE, SIZE> A;
Eigen::Matrix<double, SIZE, 1> x0;

int main() 
{  
    SimulateSystem system(A, x0);
    
    // Call stepper function from Boost library
    runge_kutta_dopri5<Eigen::Matrix<double, SIZE, 1>, double, Eigen::Matrix<double, SIZE, 1>, double, boost::numeric::odeint::vector_space_algebra> stepper;
    
    // Call numerical integrator function from Boost library
    integrate_const(stepper, ode_function, x0, 0.0, 10.0, 00.1, write_states);

    return (0);
}

// Construct the equations of motion in state-space form for N-states
void ode_function (const Eigen::Matrix<double, SIZE, 1> &x, Eigen::Matrix<double, SIZE, 1> &dxdt, double t)
{   
    dxdt = A * x;
}

// Write the quations of motion states into the text file
void write_states (const Eigen::Matrix<double, SIZE, 1> &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < 2; i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}
