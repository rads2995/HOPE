// main.cpp: source file containing main function and
// numerical integrator with stepper function
#include "simulate_system.h"

// Ordinary differential equations numerical solvers
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Write results from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

// Construct the equations of motion in state-space form
// NOTE: should work with dynamic matrix instead of explicit size
void state_function (const Eigen::Matrix<PRECISION, num_states, 1> &x, Eigen::Matrix<PRECISION, num_states, 1> &dxdt, PRECISION t)
{   
    dxdt = A * x + B * u;
}

// Write the quations of motion states into the text file
void write_states (const Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> &x, const PRECISION t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < num_states; i++)
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
    std::cout << "\nNumber of states: " << num_states << std::endl;
    
    //SimulateSystem system;
    
    /*
    // Copy object matrices to global matrices
    A = system.SimulateSystem::getA();
    B = system.SimulateSystem::getB();
    x0 = system.SimulateSystem::getx0();
    u = system.SimulateSystem::getu();
    */

    // Call stepper function (Runge-Kutta Dormand-Prince 5 method)
    runge_kutta_dopri5<Eigen::Matrix<PRECISION, num_states, 1>, PRECISION, Eigen::Matrix<PRECISION, num_states, 1>, PRECISION, vector_space_algebra> stepper;
    
    // Call integrator function (equidistant integration)
    integrate_const(stepper, state_function, x0, t0, tf, step_size, write_states);

    return (0);
}
