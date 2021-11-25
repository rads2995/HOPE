#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

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
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A;
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> B;
    Eigen::Matrix<double, Eigen::Dynamic, 1> x0;
    Eigen::Matrix<double, Eigen::Dynamic, 1> u;

public:
    // Default constructor
    SimulateSystem();

    // Default destructor 
    ~SimulateSystem();

    // Getters and Setters
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> getA();
    Eigen::Matrix<double, Eigen::Dynamic, 1> getx0();
};

#endif // SIMULATE_SYSTEM_H
