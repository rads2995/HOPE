// simulate_system.h: header file containing the SimulateSystem class
#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

// Set precision for the simulation (float, double, etc)
#define PRECISION double

// Include Eigen, a C++ template library for linear algebra 
// https://eigen.tuxfamily.org/ 
#include <Eigen/Core>

class SimulateSystem 
{
private:
    // Define member matrices [A], [B], [C], and [D]
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> m_A;
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> m_B;
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> m_C;
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> m_D;
    
    // Define member vectors {x0} and {u}
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> m_u;
    Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> m_x0;

public:
    // Default constructor
    SimulateSystem();
    
    // Overloaded constructor with global [A] and {x0}
    SimulateSystem(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_A, Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_x0);

    // Default destructor 
    ~SimulateSystem();

    // Getter methods for member matrices
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> get_m_A();
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> get_m_B();
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> get_m_C();
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> get_m_D();
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> get_m_u();
    Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> get_m_x0();
    
    // Setter methods for member matrices
    void set_m_A(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_A);
    void set_m_B(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_B);
    void set_m_C(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_C);
    void set_m_D(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_D);
    void set_m_u(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> p_u);
    void set_m_x0(Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> p_x0);
};

#endif // SIMULATE_SYSTEM_H
