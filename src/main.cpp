#include "constants.h"
#include "simulate_system.h"

// Write results from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

// Create global state matrices and initial state vector
Eigen::Matrix<PRECISION, size, size> A;
Eigen::Matrix<PRECISION, size, size> B;
Eigen::Matrix<PRECISION, size, 1> x0;
Eigen::Matrix<PRECISION, size, 1> u;

// Construct the equations of motion in state-space form
void ode_function (const Eigen::Matrix<PRECISION, size, 1> &x, Eigen::Matrix<PRECISION, size, 1> &dxdt, PRECISION t)
{   
    dxdt = A * x;
}

// Write the quations of motion states into the text file
void write_states (const Eigen::Matrix<PRECISION, size, 1> &x, const PRECISION t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < size; i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}

using namespace boost::numeric::odeint;

int main() 
{  
    std::cout << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "= Numerical Simulation =" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "\nNumber of states: " << size << std::endl;
    
    SimulateSystem system;
    
    // Copy object matrices to global matrices
    A = system.SimulateSystem::getA();
    x0 = system.SimulateSystem::getx0();
    
    // Call stepper function from Boost library
    runge_kutta_dopri5<Eigen::Matrix<PRECISION, size, 1>, PRECISION, Eigen::Matrix<PRECISION, size, 1>, PRECISION, vector_space_algebra> stepper;
    
    // Call numerical integrator function from Boost library
    integrate_const(stepper, ode_function, x0, t0, tf, step_size, write_states);

    return (0);
}
