#include "simulate_system.h"

using namespace boost::numeric::odeint;

int main() 
{  
    Eigen::Matrix<double, 2, 2> A;
    Eigen::Matrix<double, 2, 1> x0;

    SimulateSystem system(A, x0);
    
    // Call stepper function from Boost library
    runge_kutta_dopri5<Eigen::Matrix<double, 2, 1>, double, Eigen::Matrix<double, 2, 1>, double, boost::numeric::odeint::vector_space_algebra> stepper;
    
    // Call numerical integrator function from Boost library
    integrate_const(stepper, system.ode_function, x0, 0.0, 10.0, 00.1, system.write_states);

    return (0);
}
