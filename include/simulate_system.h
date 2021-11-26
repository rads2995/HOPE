// simulate_system.h: header file for 
// the SimulateSystem class containing
// the state matrices and vectors 
#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

#include "constants.h"

#include <iostream>

// Dynamic matrix sizing and matrix operations
#include <Eigen/Core>

class SimulateSystem 
{
private:
    // Define N-size state matrices and vectors
    Eigen::Matrix<PRECISION, size, size> A;
    Eigen::Matrix<PRECISION, size, size> B;
    Eigen::Matrix<PRECISION, size, 1> x0;
    Eigen::Matrix<PRECISION, size, 1> u;

public:
    // Default constructor
    SimulateSystem();

    // Default destructor 
    ~SimulateSystem();

    // Getters and Setters
    Eigen::Matrix<PRECISION, size, size> getA();
    Eigen::Matrix<PRECISION, size, size> getB();
    Eigen::Matrix<PRECISION, size, 1> getx0();
    Eigen::Matrix<PRECISION, size, 1> getu();
};

#endif // SIMULATE_SYSTEM_H
