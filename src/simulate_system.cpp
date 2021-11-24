#include "simulate_system.h"

// Write results from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

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

// Construct the equations of motion in state-space form for N-states
void SimulateSystem::ode_function (const Eigen::Matrix<double, Eigen::Dynamic, 1> &x, Eigen::Matrix<double, Eigen::Dynamic, 1> &dxdt, double t)
{   
    dxdt = A * x;
}

// Write the quations of motion states into the text file
void SimulateSystem::write_states (const Eigen::Matrix<double, Eigen::Dynamic, 1> &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < 2; i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}
