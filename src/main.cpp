#include "constants.h"
#include "simulate_system.h"

// Write results from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

// Create global state matrices and initial state vector
Eigen::Matrix<double, SIZE, SIZE> A;
Eigen::Matrix<double, SIZE, SIZE> B;
Eigen::Matrix<double, SIZE, 1> x0;
Eigen::Matrix<double, SIZE, 1> u;

// Construct the equations of motion in state-space form
void ode_function (const Eigen::Matrix<double, SIZE, 1> &x, Eigen::Matrix<double, SIZE, 1> &dxdt, double t)
{   
    dxdt = A * x;
}

// Write the quations of motion states into the text file
void write_states (const Eigen::Matrix<double, SIZE, 1> &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < SIZE; i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}

int main() 
{  
    SimulateSystem system;
    
    //A = system.SimulateSystem::getA();
    //x0 = system.SimulateSystem::getx0();

    // Call stepper function from Boost library
    //boost::numeric::odeint::runge_kutta_dopri5<Eigen::Matrix<double, SIZE, 1>, double, Eigen::Matrix<double, SIZE, 1>, double, boost::numeric::odeint::vector_space_algebra> stepper;
    
    // Call numerical integrator function from Boost library
    //boost::numeric::odeint::integrate_const(stepper, ode_function, x0, t0, tf, step_size, write_states);

    return (0);
}
