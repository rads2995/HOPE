#include "simulate_system.h"

// Default constructor
SimulateSystem::SimulateSystem() {}

// Overloaded constructor
SimulateSystem::SimulateSystem(Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A, Eigen::Matrix<double, Eigen::Dynamic, 1> x0)
{
    this->A = A; 
    this->x0 = x0;
}

// Default destructor
SimulateSystem::~SimulateSystem() {}

// Getters and Setters
Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::getA() {return this->A;}
Eigen::Matrix<double, Eigen::Dynamic, 1> SimulateSystem::getx0() {return this->x0;}
