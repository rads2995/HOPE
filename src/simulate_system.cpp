#include "simulate_system.h"

std::ofstream data("simulation.txt");

void ode_function (const state_type &x, state_type &dxdt, double t) {
    
    matrix_type A;
    A << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    dxdt = A * x;
}

void write_states (const state_type &x, const double t) {
    
    data << t << '\t' << x[0] << '\t' << x[1] << std::endl;
}
