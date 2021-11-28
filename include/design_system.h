// design_system.h: user-defined parameters for simulation
#ifndef DESIGN_SYSTEM_H
#define DESIGN_SYSTEM_H

// Dynamic matrix sizing and matrix operations
#include <Eigen/Core>

// Set precision for the simulation (float, double, etc)
#define PRECISION double

// Define {x} vector size and numerical integration parameters
constexpr unsigned int num_states = 2;  // number of states
constexpr PRECISION t0 = 0;             // initial time (s)
constexpr PRECISION tf = 50;            // final time (s)
constexpr PRECISION step_size = 0.01;   // step size (s)

// User defined constant parameters (gravity, pendulum length, etc)
// constexpr PRECISION g = 9.81;

// {dxdt} = [A]*{x} + [B]*{u}
//    {y} = [C]*{x} + [D]*{u}

Eigen::Matrix<PRECISION, num_states, num_states> A 
{{1, 2}, {3, 4}};

Eigen::Matrix<PRECISION, num_states, 1> x0
{1, 2};

Eigen::Matrix<PRECISION, num_states, num_states> B
{{1, 2}, {3, 4}};

Eigen::Matrix<PRECISION, num_states, 1> u
{1, 2};

#endif // DESIGN_SYSTEM_H
