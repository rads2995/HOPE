#include "simulate_system.h"

int main() 
{  
    state_type x0;
    x0 << 1, 2, 3;

    boost::numeric::odeint::runge_kutta_dopri5<state_type, double, state_type, double, boost::numeric::odeint::vector_space_algebra> stepper;
    
    boost::numeric::odeint::integrate_const(stepper, ode_function, x0, 0.0, 10.0, 0.1, write_states);
}
