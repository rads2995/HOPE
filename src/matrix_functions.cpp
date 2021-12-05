#include "matrix_functions.h"

// Functions to resize matrices and populate elements
void matrix_resize(state_type &m_A, state_type &m_x0, unsigned int num_states)
{
    m_A.resize(num_states, num_states); m_A.Zero(num_states, num_states);
    m_x0.resize(num_states, 1); m_x0.Zero(num_states, 1);
}

// Function to read matrix elements from text files
void matrix_read(state_type &m_A, state_type &m_x0)
{


}
