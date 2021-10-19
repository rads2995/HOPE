#include "simulate_system.h"

std::ofstream data("simulation.txt");

double g = 9.81;
double L = 5;

void ode_function (const state_type &x, state_type &dxdt, double t) {

    dxdt[0] = x[1];
    dxdt[1] = -(g/L)*x[0];
}

void write_states (const state_type &x, const double t) {
    
    data << t << '\t' << x[0] << '\t' << x[1] << std::endl;
}
