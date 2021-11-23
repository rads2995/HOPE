#include "simulate_system.h"
#include <iostream>

int main() 
{  
    state_type x0;
    x0 << 1, 2, 3;
    state_type xout = x0;

    boost::numeric::odeint::runge_kutta_dopri5<state_type, double, state_type, double, boost::numeric::odeint::vector_space_algebra> stepper;
    
    stepper.do_step([](const state_type &x, state_type &dxdt, const double t) -> void { dxdt = x; }, x0, 0.0, xout, 0.01);

    std::cout << xout << std::endl;
    
    //boost::numeric::odeint::integrate(ode_function, x, 0.0, 20.0, 0.001, write_state_types);
}
