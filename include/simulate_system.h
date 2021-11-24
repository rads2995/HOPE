#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

#include <fstream>
#include <Eigen/Core>
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

#define SIZE 3

typedef Eigen::Matrix<double, SIZE, 1> vector_type;
typedef Eigen::Matrix<double, SIZE, SIZE> matrix_type;

void ode_function (const vector_type &x, vector_type &dxdt, double t);

void write_states (const vector_type &x, const double t);

#endif // SIMULATE_SYSTEM_H
