#include "simulate_system.h"

const double sigma = 10.0;
const double R = 28.0;
const double b = 8.0 / 3.0;

std::ofstream data("simulation.txt");

void equation (const state_type &x, state_type &dxdt, double t) {

    dxdt[0] = sigma * (x[1] - x[0]);
    dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
    dxdt[2] = -b * x[2] + x[0] * x[1];
}

void output (const state_type &x, const double t) {
    
    data << t << '\t' << x[0] << '\t' << x[1] << '\t' << x[2] << std::endl;
}
