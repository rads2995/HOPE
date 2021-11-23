#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

#include <fstream>
#include <Eigen/Core>
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>

typedef Eigen::Matrix<double, 3, 1> state_type;

void ode_function (const state_type &x, state_type &dxdt, double t);

void write_states (const state_type &x, const double t);

#endif // SIMULATE_SYSTEM_H
