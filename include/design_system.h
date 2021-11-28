// design_system.h: user-defined parameters for simulation
#ifndef DESIGN_SYSTEM_H
#define DESIGN_SYSTEM_H

// Include Eigen, a C++ template library for linear algebra 
// https://eigen.tuxfamily.org/ 
#include <Eigen/Core>

// Set precision for the simulation (float, double, etc)
#define PRECISION double

/*
// Define {x} vector size and numerical integration parameters
constexpr unsigned int num_states = 2;  // number of states
constexpr PRECISION t0 = 0;             // initial time (s)
constexpr PRECISION tf = 50;            // final time (s)
constexpr PRECISION step_size = 0.01;   // step size (s)

// Define your dynamical system in the state-space form:
// {dxdt} = [A]*{x} + [B]*{u}
//    {y} = [C]*{x} + [D]*{u}

// If A is 2x2: {{A(0,0), A(0,1)}, {A(1,0), A(1,1)}}
Eigen::Matrix<PRECISION, num_states, num_states> A 
{{0, 1}, {-0.5, -1}};

// If x0 is 2x1: {x0(0), x0(1)}
Eigen::Matrix<PRECISION, num_states, 1> x0
{0, 0.5};
*/
/*
Eigen::Matrix<PRECISION, num_states, num_states> B
{{1, 2}, {3, 4}};

Eigen::Matrix<PRECISION, num_states, 1> u
{1, 2};
*/
#endif // DESIGN_SYSTEM_H
