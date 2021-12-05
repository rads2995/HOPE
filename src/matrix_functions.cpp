#include "matrix_functions.h"

// Functions to resize matrices and populate elements
void matrix_resize(state_type &m_A, state_type &m_x0, unsigned int size)
{
    m_A.resize(size, size); m_A.Zero(size, size);
    m_x0.resize(size, 1); m_x0.Zero(size, 1);
}

// Function to read matrix elements from text files
void matrix_read(state_type &m_A, state_type &m_x0)
{


}
