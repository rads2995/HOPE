#ifndef SIMULATE_SYSTEM_H_
#define SIMULATE_SYSTEM_H_

#include <fstream>
#include <array>

#include <boost/numeric/odeint.hpp>

typedef std::array<double, 2> state_type;

void ode_function (const state_type &x, state_type &dxdt, double t);

void write_states (const state_type &x, const double t);

#endif // SIMULATE_SYSTEM_H_
