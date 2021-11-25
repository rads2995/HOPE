#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

#include "constants.h"

#include <fstream>

// Dynamic matrix sizing and operations
#include <Eigen/Core>

// Ordinary differential equations numerical solvers
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

class SimulateSystem 
{
private:
    // Define dynamic state matrices and vectors
    Eigen::Matrix<double, size, size> A;
    Eigen::Matrix<double, size, size> B;
    Eigen::Matrix<double, size, 1> x0;
    Eigen::Matrix<double, size, 1> u;

public:
    // Default constructor
    SimulateSystem();

    // Default destructor 
    ~SimulateSystem();

    // Getters and Setters
    Eigen::Matrix<double, size, size> getA();
    Eigen::Matrix<double, size, 1> getx0();
};

#endif // SIMULATE_SYSTEM_H
