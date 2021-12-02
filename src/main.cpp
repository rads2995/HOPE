// main.cpp: source file containing main function and
// numerical integrator with stepper function
#include "simulate_system.h"

// Ordinary differential equations numerical solvers
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Write results from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

// Define global matrices [A], [B], [C], [D] and vectors {u} and {x0}
matrix_type A = matrix_type::Zero(2, 2);
matrix_type B = matrix_type::Zero(1, 1);
matrix_type C = matrix_type::Zero(1, 1);
matrix_type D = matrix_type::Zero(1, 1);
matrix_type u = matrix_type::Zero(1, 1);
vector_type x0 = vector_type::Zero(2, 1);

// Construct the equations of motion in state-space form
void state_function (const Eigen::Matrix<double, Eigen::Dynamic, 1> &x, Eigen::Matrix<double, 1, 1> &dxdt, double t)
{   
    // Introduce temporary vector?
    dxdt = A * x;
}

// Write the system's states into the text file
void write_states (Eigen::Matrix<double, Eigen::Dynamic, 1> &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}

using namespace boost::numeric::odeint;

int main() 
{  
    // Create system object using global matrices
    SimulateSystem system(A, B, C, D, u, x0); 
   
    // Resize matrices
    system.read_matrices();
   
    // Local simulation parameters
    double t0 = 0;             // initial time (s)
    double tf = 1;            // final time (s)
    double step_size = 0.1;   // step size (s)
    
    // Print user-defined simulation parameters to the console
    std::cout << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "= Numerical Simulation =" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << " Number of states: " << 1 << std::endl;
    std::cout << " Initial time: " << t0 << "s" << std::endl;
    std::cout << " Final time: " << tf << "s" << std::endl;
    std::cout << " Time step: " << step_size << "s" << std::endl;
    std::cout << "========================" << std::endl;
    
    // Copy object's matrices back to the global matrices
    A = system.get_m_A();
    //B = system.get_m_B();
    //C = system.get_m_B();
    //D = system.get_m_D();
    //u = system.get_m_u();
    x0 = system.get_m_x0();
    
    // Call stepper function (Runge-Kutta Dormand-Prince 5 method)
    runge_kutta_dopri5<Eigen::Matrix<double, Eigen::Dynamic, 1>, double, Eigen::Matrix<double, 1, 1>, double, vector_space_algebra> stepper;
    // Call integrator function (equidistant integration)
    integrate_const(stepper, state_function, x0, t0, tf, step_size, write_states);

    return (0);
}
