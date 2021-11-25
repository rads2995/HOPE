// simulate_system.h: source file for 
// the SimulateSystem class containing
// the state matrices and vectors 
#include "constants.h"
#include "simulate_system.h"

// Default constructor
SimulateSystem::SimulateSystem() 
{
    // Generate components for state matrix [A]
    std::cout << "Define the components of matrix [A]" << std::endl;
    for(size_t i = 0; i < size; i++)
        for(size_t j = 0; j < size; j++)
        {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> this->A(i,j);
        } std::cout << std::endl;

    // Generate components for state vector {x}
    std::cout << "Define the components of vector {x0}" << std::endl;
    for(size_t i = 0; i < size; i++)
    {
        std::cout << "x0[" << i << "]: ";
        std::cin >> this->x0(i);
    } std::cout << std::endl;
}

// Default destructor
SimulateSystem::~SimulateSystem() {}

// Getters and Setters
Eigen::Matrix<PRECISION, size, size> SimulateSystem::getA() {return this->A;}
Eigen::Matrix<PRECISION, size, 1> SimulateSystem::getx0() {return this->x0;}
