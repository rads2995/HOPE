#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

#include <iostream>
#include <fstream>

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
    
    // Function describing the state-space system
    void ode_function (const Eigen::Matrix<double, Eigen::Dynamic, 1> &x, Eigen::Matrix<double, Eigen::Dynamic, 1> &dxdt, double t);
    
    // Function to write the resultant states
    void write_states (const Eigen::Matrix<double, Eigen::Dynamic, 1> &x, const double t);
};

#endif // SIMULATE_SYSTEM_H
