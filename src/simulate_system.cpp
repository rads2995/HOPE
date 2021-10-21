#include "simulate_system.h"

std::ofstream data("simulation.txt");

void ode_function (const state_type &x, state_type &dxdt, double t) {
    
    dxdt[0] = x[0]*x[0];
}

void write_states (const state_type &x, const double t) {
    
    data << t << '\t' << x[0] << '\t' << x[1] << std::endl;
}
