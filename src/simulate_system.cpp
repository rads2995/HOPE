// simulate_system.h: source file containing the SimulateSystem class implementation
#include "simulate_system.h"

// Read text files containing elements for all matrices
std::ifstream file_A("data/A.txt");
std::ifstream file_B("data/B.txt");
std::ifstream file_C("data/C.txt");
std::ifstream file_D("data/D.txt");
std::ifstream file_u("data/u.txt");
std::ifstream file_x0("data/x0.txt");

// Default constructor
SimulateSystem::SimulateSystem() {}

// Overloaded constructor with global [A], [B], [C], [D], {u} and {x0}
SimulateSystem::SimulateSystem(matrix_type p_A, matrix_type p_B, matrix_type p_C, matrix_type p_D, matrix_type p_u, vector_type p_x0)
{
    m_A = p_A;
    m_B = p_B;
    m_C = p_C;
    m_D = p_D;
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


void SimulateSystem::matrix_resize()
{
    m_A.resize(2,2);
    m_B.resize(2,2);
    m_x0.resize(2,1);
    m_u.resize(2,1);
}

// Read matrices from files 
void SimulateSystem::read_matrices()
{

}
