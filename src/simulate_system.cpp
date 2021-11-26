// simulate_system.h: source file for 
// the SimulateSystem class containing
// the state matrices and vectors 
#include "constants.h"
#include "simulate_system.h"

// Default constructor
SimulateSystem::SimulateSystem() 
{
    //TODO: Option to instead read matrices/vectors from file 
    
    // Generate components for state matrix [A]
    std::cout << "Define the elements for the state matrix [A]" << std::endl;
    for(size_t i = 0; i < size; i++)
        for(size_t j = 0; j < size; j++)
        {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> this->A(i,j);
        } std::cout << std::endl;
    
    // Generate components for state matrix [B]
    std::cout << "Define the elements for the input matrix [B]" << std::endl;
    for(size_t i = 0; i < size; i++)
        for(size_t j = 0; j < size; j++)
        {
            std::cout << "B[" << i << "][" << j << "]: ";
            std::cin >> this->B(i,j);
        } std::cout << std::endl;

    // Generate components for state vector {u}
    std::cout << "Define the elements for the input vector {u}" << std::endl;
    for(size_t i = 0; i < size; i++)
    {
        std::cout << "u[" << i << "]: ";
        std::cin >> this->u(i);
    } std::cout << std::endl;
    
    // Generate components for state vector {x}
    std::cout << "Define the elements for the initial state vector {x0}" << std::endl;
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
Eigen::Matrix<PRECISION, size, size> SimulateSystem::getB() {return this->B;}
Eigen::Matrix<PRECISION, size, 1> SimulateSystem::getx0() {return this->x0;}
Eigen::Matrix<PRECISION, size, 1> SimulateSystem::getu() {return this->u;}
