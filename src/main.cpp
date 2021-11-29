// main.cpp: source file containing main function and
// numerical integrator with stepper function
#include "simulate_system.h"

// Ordinary differential equations numerical solvers
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Write results from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

// Define {x} vector size and numerical integration parameters
PRECISION t0 {}, tf {}, step_size {};

// Define global matrices [A], [B], [C], [D] and vectors {u} and {x0}
matrix_type A = matrix_type::Zero(num_states, num_states);
matrix_type B = matrix_type::Zero(num_states, num_states);
matrix_type C = matrix_type::Zero(num_states, num_states);
matrix_type D = matrix_type::Zero(num_states, num_states);
matrix_type u = matrix_type::Zero(num_states, 1);
vector_type x0 = vector_type::Zero(num_states, 1);

// Construct the equations of motion in state-space form
void state_function (const Eigen::Matrix<PRECISION, num_states, 1> &x, Eigen::Matrix<PRECISION, num_states, 1> &dxdt, PRECISION t)
{   
    dxdt = A * x + B * u;
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
    // Create system object using global matrices
    SimulateSystem system(A, B, C, D, u, x0); 
   
    system.matrix_resize();
   
    // Local simulation parameters
    PRECISION m_t0 = 0;             // initial time (s)
    PRECISION m_tf = 50;            // final time (s)
    PRECISION m_step_size = 0.01;   // step size (s)
    
    // Print user-defined simulation parameters to the console
    std::cout << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "= Numerical Simulation =" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << " Number of states: " << num_states << std::endl;
    std::cout << " Initial time: " << m_t0 << "s" << std::endl;
    std::cout << " Final time: " << m_tf << "s" << std::endl;
    std::cout << " Time step: " << m_step_size << "s" << std::endl;
    std::cout << "========================" << std::endl;
    
    // Copy object's matrices back to the global matrices
    A = system.get_m_A();
    B = system.get_m_B();
    C = system.get_m_B();
    D = system.get_m_D();
    u = system.get_m_u();
    x0 = system.get_m_x0();
    t0 = m_t0;
    tf = m_tf;
    step_size = m_step_size;
    
    // Call stepper function (Runge-Kutta Dormand-Prince 5 method)
    //runge_kutta_dopri5<Eigen::Matrix<PRECISION, num_states, 1>, PRECISION, Eigen::Matrix<PRECISION, num_states, 1>, PRECISION, vector_space_algebra> stepper;
    // Call integrator function (equidistant integration)
    //integrate_const(stepper, state_function, x0, t0, tf, step_size, write_states);

    return (0);
}
