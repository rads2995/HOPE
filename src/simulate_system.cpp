// simulate_system.h: source file containing the SimulateSystem class implementation
#include "simulate_system.h"

// TODO: overload constructor with all matrices and vectors from global
// definition

// Default constructor
SimulateSystem::SimulateSystem() 
{
    /* GOTTA FIGURE OUT BETTER IMPLEMENTATION!
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
    */
}

// Default destructor
SimulateSystem::~SimulateSystem() {}

// Getter methods
Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::get_A() {return this->A;}
Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::get_B() {return this->B;}
Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::get_C() {return this->C;}
Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::get_D() {return this->D;}
Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::get_u() {return this->u;}
Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> SimulateSystem::get_x0() {return this->x0;}

// Setter methods
void SimulateSystem::set_A(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> A) {this->A = A;}
void SimulateSystem::set_B(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> B) {this->B = B;}
void SimulateSystem::set_C(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> C) {this->C = C;}
void SimulateSystem::set_D(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> D) {this->D = D;}
void SimulateSystem::set_u(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> u) {this->u = u;}
void SimulateSystem::set_x0(Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> x0) {this->x0 = x0;}
