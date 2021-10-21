#include "simulate_system.h"

int main() {
    
    Eigen::Matrix<double, 3, 3> A {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};
    
    Eigen::Matrix<double, 3, 1> x {1, 2, 3};

    Eigen::MatrixXd Ax = A*x;
    
    std::cout << Ax << std::endl;
    
    //state_type x;
    //x.push_back(1.0);
    //x.push_back(1.0);
    //boost::numeric::odeint::integrate(ode_function, x, 0.0, 20.0, 0.001, write_states);
}
