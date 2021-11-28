// main.cpp: source file containing main function and
// numerical integrator with stepper function
#include "simulate_system.h"

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

// All matrices and vectors are initialized to zero
// Matrix [A] and vector {x0} dimensions are determined by the number of states (num_states) variable
// For the rest, adjust dimensions as needed, for example: Eigen::Matrix<PRECISION, rows, columns> B
Eigen::Matrix<PRECISION, num_states, num_states> A = Eigen::Matrix<PRECISION, num_states, num_states>::Zero();
Eigen::Matrix<PRECISION, num_states, 1> x0 = Eigen::Matrix<PRECISION, num_states, 1>::Zero(); 
//Eigen::Matrix<PRECISION, , > B = Eigen::Matrix<PRECISION, , >::Zero();
//Eigen::Matrix<PRECISION, , > C = Eigen::Matrix<PRECISION, , >::Zero();
//Eigen::Matrix<PRECISION, , > D = Eigen::Matrix<PRECISION, , >::Zero();
//Eigen::Matrix<PRECISION, , > u = Eigen::Matrix<PRECISION, , >::Zero();

// Construct the equations of motion in state-space form
void state_function (const Eigen::Matrix<PRECISION, num_states, 1> &x, Eigen::Matrix<PRECISION, num_states, 1> &dxdt, PRECISION t)
{   
    dxdt = A * x; // + B * u;
}

// Write the system's states into the text file
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
    // Print user-defined simulation parameters to the console
    std::cout << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "= Numerical Simulation =" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "= Number of states: " << num_states << "  =" << std::endl;
    std::cout << "= Initial time: " << t0 << "s     =" << std::endl;
    std::cout << "= Final time: " << tf << "s      =" << std::endl;
    std::cout << "= Time step: " << step_size << "s     =" << std::endl;
    std::cout << "========================" << std::endl;
    
    // Create system object using global matrices
    SimulateSystem system(A, x0);
    
    // Copy object's matrices back to the global matrices
    A = system.get_m_A();
    //B = system.get_m_B();
    //u = system.get_m_u();
    x0 = system.get_m_x0();
    
    // Call stepper function (Runge-Kutta Dormand-Prince 5 method)
    runge_kutta_dopri5<Eigen::Matrix<PRECISION, num_states, 1>, PRECISION, Eigen::Matrix<PRECISION, num_states, 1>, PRECISION, vector_space_algebra> stepper;
    // Call integrator function (equidistant integration)
    integrate_const(stepper, state_function, x0, t0, tf, step_size, write_states);

    return (0);
}
