// simulate_system.h: source file containing the SimulateSystem class implementation
#include "simulate_system.h"

// Default constructor
SimulateSystem::SimulateSystem() {}

// Overloaded constructor with global [A] and {x0}
SimulateSystem::SimulateSystem(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_A, Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_x0)
{
    m_A = p_A;
    m_x0 = p_x0;
}

// Default destructor
SimulateSystem::~SimulateSystem() {}

// Getter methods
Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::get_m_A() {return m_A;}
Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::get_m_B() {return m_B;}
Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::get_m_C() {return m_C;}
Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::get_m_D() {return m_D;}
Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> SimulateSystem::get_m_u() {return m_u;}
Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> SimulateSystem::get_m_x0() {return m_x0;}

// Setter methods
void SimulateSystem::set_m_A(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_A) {m_A = p_A;}
void SimulateSystem::set_m_B(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_B) {m_B = p_B;}
void SimulateSystem::set_m_C(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_C) {m_C = p_C;}
void SimulateSystem::set_m_D(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_D) {m_D = p_D;}
void SimulateSystem::set_m_u(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_u) {m_u = p_u;}
void SimulateSystem::set_m_x0(Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> p_x0) {m_x0 = p_x0;}

/* GOTTA FIGURE OUT BETTER IMPLEMENTATION! (code to use later)
    // Generate components for state matrix [A]
    std::cout << "Define the elements for the state matrix [A]" << std::endl;
    for(size_t i = 0; i < size; i++)
        for(size_t j = 0; j < size; j++)
        {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> this->A(i,j);
        } std::cout << std::endl;
    
    // Generate components for state vector {x}
    std::cout << "Define the elements for the initial state vector {x0}" << std::endl;
    for(size_t i = 0; i < size; i++)
    {
        std::cout << "x0[" << i << "]: ";
        std::cin >> this->x0(i);
    } std::cout << std::endl;
*/
