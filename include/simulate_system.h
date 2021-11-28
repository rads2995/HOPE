// simulate_system.h: header file containing the SimulateSystem class
#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

#include "design_system.h"

#include <iostream>
#include <fstream>

class SimulateSystem 
{
private:
    // Define matrices [A], [B], [C], and [D]
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> A;
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> B;
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> C;
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> D;
    
    // Define vectors {x0} and {u}
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> u;
    Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> x0;

public:
    // Default constructor
    SimulateSystem();

    // Default destructor 
    ~SimulateSystem();

    // Getter methods
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> get_A();
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> get_B();
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> get_C();
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> get_D();
    Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> get_u();
    Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> get_x0();
    
    // Setter methods
    void set_A(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> A);
    void set_B(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> B);
    void set_C(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> C);
    void set_D(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> D);
    void set_u(Eigen::Matrix<PRECISION, Eigen::Dynamic, Eigen::Dynamic> u);
    void set_x0(Eigen::Matrix<PRECISION, Eigen::Dynamic, 1> x0);
};

#endif // SIMULATE_SYSTEM_H
