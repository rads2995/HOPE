// simulate_system.h: header file containing the SimulateSystem class
#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

// Set precision for the simulation (float, double, etc)
#define PRECISION double

// Include Eigen, a C++ template library for linear algebra 
// https://eigen.tuxfamily.org/ 
#include <Eigen/Core>

// Define types for dynamic matrix and dynamic vector 
typedef Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> matrix_type;
typedef Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> vector_type;

class SimulateSystem 
{
private:
    // Define member matrices and vectors
    matrix_type m_A, m_B, m_C, m_D, m_u;
    vector_type m_x0;

public:
    // Default constructor
    SimulateSystem();
    
    // Overloaded constructor with global [A] and {x0}
    SimulateSystem(matrix_type p_A, vector_type p_x0);
    
    // Overloaded constructor with global [A], {x0}, [B] and {u}
    SimulateSystem(matrix_type p_A, vector_type p_x0, matrix_type p_B, matrix_type p_u);

    // Default destructor 
    ~SimulateSystem();

    // Getter methods for member matrices
    matrix_type get_m_A();
    matrix_type get_m_B();
    matrix_type get_m_C();
    matrix_type get_m_D();
    matrix_type get_m_u();
    vector_type get_m_x0();
    
    // Setter methods for member matrices
    void set_m_A(matrix_type p_A);
    void set_m_B(matrix_type p_B);
    void set_m_C(matrix_type p_C);
    void set_m_D(matrix_type p_D);
    void set_m_u(matrix_type p_u);
    void set_m_x0(vector_type p_x0);
};

#endif // SIMULATE_SYSTEM_H
