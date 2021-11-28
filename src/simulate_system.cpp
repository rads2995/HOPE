// simulate_system.h: source file containing the SimulateSystem class implementation
#include "simulate_system.h"

// Default constructor
SimulateSystem::SimulateSystem() {}

// Overloaded constructor with global [A] and {x0}
SimulateSystem::SimulateSystem(matrix_type p_A, vector_type p_x0)
{
    m_A = p_A;
    m_x0 = p_x0;
}

SimulateSystem::SimulateSystem(matrix_type p_A, vector_type p_x0, matrix_type p_B, matrix_type p_u)
{
    m_A = p_A;
    m_B = p_B;
    m_u = p_u;
    m_x0 = p_x0;
}

// Default destructor
SimulateSystem::~SimulateSystem() {}

// Getter methods
matrix_type SimulateSystem::get_m_A() {return m_A;}
matrix_type SimulateSystem::get_m_B() {return m_B;}
matrix_type SimulateSystem::get_m_C() {return m_C;}
matrix_type SimulateSystem::get_m_D() {return m_D;}
matrix_type SimulateSystem::get_m_u() {return m_u;}
vector_type SimulateSystem::get_m_x0() {return m_x0;}

// Setter methods
void SimulateSystem::set_m_A(matrix_type p_A) {m_A = p_A;}
void SimulateSystem::set_m_B(matrix_type p_B) {m_B = p_B;}
void SimulateSystem::set_m_C(matrix_type p_C) {m_C = p_C;}
void SimulateSystem::set_m_D(matrix_type p_D) {m_D = p_D;}
void SimulateSystem::set_m_u(matrix_type p_u) {m_u = p_u;}
void SimulateSystem::set_m_x0(vector_type p_x0) {m_x0 = p_x0;}
