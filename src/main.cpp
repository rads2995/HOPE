#include "simulate_system.h"

int main() {
    
    state_type x = {1, 2};
    boost::numeric::odeint::integrate (ode_function, x, 0.0, 10.0, 0.01, write_states);
    return 0;
}
