// main.cpp: source file containing main function and
// numerical integrator with stepper function
#include "simulate_system.h"

#include <iostream>
#include <fstream>

// Ordinary differential equations numerical solvers
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Write results from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

// Define {x} vector size and numerical integration parameters
constexpr unsigned int num_states = 2;  // number of states
constexpr PRECISION t0 = 0;             // initial time (s)
constexpr PRECISION tf = 50;            // final time (s)
constexpr PRECISION step_size = 0.01;   // step size (s)

// Define your dynamical system in the state-space form:
// {dxdt} = [A]*{x} + [B]*{u}
//    {y} = [C]*{x} + [D]*{u}

// If A is 2x2: {{A(0,0), A(0,1)}, {A(1,0), A(1,1)}}
Eigen::Matrix<PRECISION, num_states, num_states> A 
{{0, 1}, {-0.5, -1}};

// If x0 is 2x1: {x0(0), x0(1)}
Eigen::Matrix<PRECISION, num_states, 1> x0
{0, 0.5};

// Construct the equations of motion in state-space form
// NOTE: should work with dynamic matrix instead of explicit size
void state_function (const Eigen::Matrix<PRECISION, num_states, 1> &x, Eigen::Matrix<PRECISION, num_states, 1> &dxdt, PRECISION t)
{   
    dxdt = A * x; // + B * u;
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
    
    SimulateSystem system(A, x0);
    
    // TEST: display member matrix [A] after construction
    std::cout << system.SimulateSystem::get_m_A() << std::endl;

    // Call stepper function (Runge-Kutta Dormand-Prince 5 method)
    runge_kutta_dopri5<Eigen::Matrix<PRECISION, num_states, 1>, PRECISION, Eigen::Matrix<PRECISION, num_states, 1>, PRECISION, vector_space_algebra> stepper;
    
    // Call integrator function (equidistant integration)
    integrate_const(stepper, state_function, x0, t0, tf, step_size, write_states);

    return (0);
}
