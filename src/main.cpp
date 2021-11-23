#include "simulate_system.h"
#include <iostream>

using namespace Eigen;
using namespace boost::numeric::odeint;


template<size_t N>
    using vector = Matrix<double, N, 1>;

typedef vector<3> state;

int main() 
{  
    state x0;
    x0 << 1., 2., 3.;
    state xout = x0;

    runge_kutta_dopri5<state,double,state,double,vector_space_algebra> stepper;
    
    stepper.do_step([](const state &x, state &dxdt, const double t) -> void { dxdt = x; }, x0, 0.0, xout, 0.01);

    std::cout << xout << std::endl;
    
/*    
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
*/
}
