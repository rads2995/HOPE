// matrix_functions.cpp: source file containing matrix functions implementation
#include "matrix_functions.h"

unsigned int read_num_states()
{
    unsigned int num_rows {0};

    std::ifstream read_x0("data/x0.txt");

    // Obtain number of rows from {x0} vector
    read_x0 >> num_rows;

    return num_rows;
}

// Function to read matrix elements from text files
void matrix_read(state_type &m_A, state_type &m_B, state_type &m_C, state_type &m_D, state_type &m_u, state_type &m_x0, state_type &m_y)
{
    unsigned int num_rows {0}, num_cols {0};

    // Read matrix and vector data text files
    std::ifstream read_A("data/A.txt");
    std::ifstream read_B("data/B.txt");
    std::ifstream read_C("data/C.txt");
    std::ifstream read_D("data/D.txt");
    std::ifstream read_u("data/u.txt");
    std::ifstream read_x0("data/x0.txt");

    // Matrix [A]
    read_A >> num_rows;
    read_A >> num_cols;
    m_A.resize(num_rows, num_cols);

    for (size_t i = 0; i < num_rows; i++)
        for (size_t j = 0; j < num_cols; j++)
            read_A >> m_A(i,j);

    // Matrix [B]
    read_B >> num_rows;
    read_B >> num_cols;
    m_B.resize(num_rows, num_cols);

    for (size_t i = 0; i < num_rows; i++)
        for (size_t j = 0; j < num_cols; j++)
            read_B >> m_B(i,j);

    // Matrix [C]
    read_C >> num_rows;
    read_C >> num_cols;
    m_C.resize(num_rows, num_cols);
    m_y.resize(num_rows, 1);

    for (size_t i = 0; i < num_rows; i++)
        for (size_t j = 0; j < num_cols; j++)
            read_C >> m_C(i,j);

    // Matrix [D]
    read_D >> num_rows;
    read_D >> num_cols;
    m_D.resize(num_rows, num_cols);

    for (size_t i = 0; i < num_rows; i++)
        for (size_t j = 0; j < num_cols; j++)
            read_D >> m_D(i,j);

    // Vector {u}
    read_u >> num_rows;
    read_u >> num_cols;
    m_u.resize(num_rows, num_cols);

    for (size_t i = 0; i < num_rows; i++)
        for (size_t j = 0; j < num_cols; j++)
            read_u >> m_u(i,j);
    
    // Vector {x0}
    read_x0 >> num_rows;
    read_x0 >> num_cols;
    m_x0.resize(num_rows, num_cols);

    for (size_t i = 0; i < num_rows; i++)
        for (size_t j = 0; j < num_cols; j++)
            read_x0 >> m_x0(i,j);
}
