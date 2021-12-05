#include "matrix_functions.h"

// Functions to resize matrices and populate elements
void matrix_resize(state_type &m_A, state_type &m_B, state_type &m_C, state_type &m_D, state_type &m_u, state_type &m_x0, unsigned int size)
{
    // TODO: define prompt menu to allow user to define new dimensions for matrices and vectors

    m_A.resize(size, size); m_A.Zero(size, size);
    m_B.resize(size, size); m_B.Zero(size, size);
    m_C.resize(size, size); m_C.Zero(size, size);
    m_D.resize(size, size); m_D.Zero(size, size);
    m_u.resize(size, 1); m_u.Zero(size, 1);
    m_x0.resize(size, 1); m_x0.Zero(size, 1);
}

// Function to read matrix elements from text files
void matrix_read(state_type &m_A, state_type &m_B, state_type &m_C, state_type &m_D, state_type &m_u, state_type &m_x0)
{

}
