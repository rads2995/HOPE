// constants.h: user defined parameters for simulation
#ifndef CONSTANTS_H
#define CONSTANTS_H

// Set precision for the simulation (float, double, etc)
#define PRECISION double

// Define constant parameters
constexpr unsigned int size = 2;        // number of states
constexpr PRECISION t0 = 0;             // initial time (s)
constexpr PRECISION tf = 50;            // final time (s)
constexpr PRECISION step_size = 0.01;   // step size (s)

// User defined constant parameters (gravity, pendulum length, etc)
// constexpr PRECISION g = 9.81;

#endif // CONSTANTS_H
