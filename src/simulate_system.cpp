#include "constants.h"
#include "simulate_system.h"

// Default constructor
SimulateSystem::SimulateSystem() 
{
    // Generate components for state matrix [A]
    std::array<std::array<double, SIZE>, SIZE> temp = {{{0, 1}, {-5, 0}}};
    /*
    for(size_t i = 0; i < SIZE; i++)
        for(size_t j = 0; j < SIZE; j++)
            this->A(i,j) = temp[i][j];
    */
    // Generate components for state vector {x}
    std::array<double, SIZE> temp_vector = {0.1, 0.2};
    /*
    for(size_t i = 0; i < SIZE; i++)
        this->x0(i) = temp_vector[i];
    */
}

// Default destructor
SimulateSystem::~SimulateSystem() {}

// Getters and Setters
Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::getA() {return this->A;}
Eigen::Matrix<double, Eigen::Dynamic, 1> SimulateSystem::getx0() {return this->x0;}
