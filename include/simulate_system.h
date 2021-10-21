#ifndef HOPE_SIMULATE_SYSTEM_H
#define HOPE_SIMULATE_SYSTEM_H

#include <fstream>
#include <vector>

#include <Eigen/Core>
#include <boost/numeric/odeint.hpp>

typedef std::vector<double> state_type;

void ode_function (const state_type &x, state_type &dxdt, double t);

void write_states (const state_type &x, const double t);

#endif // SIMULATE_SYSTEM_H
