#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

#include <iostream>
#include <fstream>

#include <Eigen/Core>
#include <boost/numeric/odeint.hpp>
#include <boost/numeric/odeint/external/eigen/eigen_algebra.hpp>

typedef std::array<double, 3> state_type;

void equation (const state_type &x, state_type &dxdt, double t);

void output (const state_type &x, const double t);

#endif // SIMULATE_SYSTEM_H
