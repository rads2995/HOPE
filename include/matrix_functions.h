#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H

#include "simulate_system.h"

// Function to resize matrices and populate elements with zeros
void matrix_resize(state_type &m_A, state_type &m_B, state_type &m_C, state_type &m_D, state_type &m_u, state_type &m_x0, unsigned int size);

// Function to read matrix elements from text files
void matrix_read(state_type &m_A, state_type &m_B, state_type &m_C, state_type &m_D, state_type &m_u, state_type &m_x0);

#endif // MATRIX_FUNCTIONS_H
