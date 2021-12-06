// matrix_functions.cpp: source file containing matrix functions implementation
#include "matrix_functions.h"

// Function to read matrix elements from text files
void matrix_read(state_type &m_A, state_type &m_B, state_type &m_C, state_type &m_D, state_type &m_u, state_type &m_x0, unsigned int size)
{
    unsigned int num_rows {0}, num_cols {0};
    std::string temp{};

    // Read matrix and vector data text files
    std::ifstream read_A("data/A.txt");
    std::ifstream read_B("data/B.txt");
    std::ifstream read_C("data/C.txt");
    std::ifstream read_D("data/D.txt");
    std::ifstream read_u("data/u.txt");
    std::ifstream read_x0("data/x0.txt");

    // Matrix [A]
    m_A.resize(size, size);

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            read_A >> m_A(i,j);
        }
    }

    // Vector {x0}
    m_x0.resize(size, 1);

    for (size_t i = 0; i < size; i++)
        read_x0 >> m_x0(i,0);
}
