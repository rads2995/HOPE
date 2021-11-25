#include "constants.h"
#include "simulate_system.h"

// Default constructor
SimulateSystem::SimulateSystem() 
{
    // Generate components for state matrix [A]
    //std::array<std::array<double, size>, size> temp = {{{0, 1}, {-5, 0}}};
    //this->A = temp;
    
    this->A << 1, 2, 3, 4;
    
    /*
    for(size_t i = 0; i < size; i++)
        for(size_t j = 0; j < size; j++)
            this->A(i,j) = temp[i][j];
    */
    // Generate components for state vector {x}
    //std::array<double, size> temp_vector = {0.1, 0.2};
    
    this->x0 << 1, 2;
    
    /*
    for(size_t i = 0; i < size; i++)
        this->x0(i) = temp_vector[i];
    */
}

// Default destructor
SimulateSystem::~SimulateSystem() {}

// Getters and Setters
Eigen::Matrix<double, size, size> SimulateSystem::getA() {return this->A;}
Eigen::Matrix<double, size, 1> SimulateSystem::getx0() {return this->x0;}
