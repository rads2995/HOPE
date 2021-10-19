#include "simulate_system.h"

int main() {
    
    state_type x = {10, 0.5}; 
    boost::numeric::odeint::integrate (ode_function, x, 0.0, 50.0, 0.01, write_states);
    return 0;
}
