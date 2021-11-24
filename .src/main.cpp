#include "simulate_system.hpp"

using namespace boost::numeric::odeint;

int main() 
{  
    // Define the number of states for the simulation
    const unsigned int N = 2;

    // User must input initial state vector values
    // TODO: simplify double loop into single loop - Rodrigo
    Eigen::Matrix<double, N, 1> x0;
    std::array<double, N> temp; 
    std::cout << "\nEnter the initial state vector (x0) values: ";
    
    // NOTE: There is no overload operator for '>>' for Eigen::Matrix type
    for (size_t i = 0; i < N; i++)
        std::cin >> temp[i];

    for (size_t i = 0; i < N; i++)
        x0(i,0) = temp[i];

    // Call stepper function from Boost library
    runge_kutta_dopri5<Eigen::Matrix<double, N, 1>, double, Eigen::Matrix<double, N, 1>, double, boost::numeric::odeint::vector_space_algebra> stepper;
    
    // Call numerical integrator function from Boost library
    integrate_const(stepper, ode_function<N>, x0, 0.0, 10.0, 00.1, write_states<N>);

    return (0);
}
