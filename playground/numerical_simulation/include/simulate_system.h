#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

#include <iostream>
#include <fstream>

#include <boost/numeric/odeint.hpp>

void equation (const std::array <double, 3> &x, std::array <double, 3> &dxdt, double t);

void output (const std::array <double, 3> &x, const double t);

#endif // SIMULATE_SYSTEM_H
