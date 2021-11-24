#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

#include <iostream>
#include <fstream>

// Eigen (matrix operations) library and Boost (numerical solver) library
#include <Eigen/Core>
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

class SimulateSystem 
{
private:
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A;
    Eigen::Matrix<double, Eigen::Dynamic, 1> x0;

public:
    // Default constructor
    SimulateSystem();

    // Overloaded constructor
    SimulateSystem(Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A, Eigen::Matrix<double, Eigen::Dynamic, 1> x0);
    
    // Default destructor 
    ~SimulateSystem();
    
    // Getters and Setters
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> getA();
    Eigen::Matrix<double, Eigen::Dynamic, 1> getx0();
};

#endif // SIMULATE_SYSTEM_H
