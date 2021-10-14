#include "matrix.hpp"
#include <Eigen/Dense>
#include <iostream>

using Eigen::MatrixXd;

void PrintMatrix() {

    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 3;
    m(0,1) = 3;
    m(1,1) = 3;
    std::cout << m << std::endl;
}
