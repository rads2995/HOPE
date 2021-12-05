// main.cpp: source file containing main function
#include "simulate_system.h"

using namespace boost::numeric::odeint;

// Define global matrices and vectors 
state_type A, B, C, D, u, x0;

template<typename T>
void state_function (const T &x, T &dxdt, double t)
{
    dxdt = A * x + B * u;
}

template<typename T>
void write_states (const T &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}

int main() 
{  
    double t0 {0}, tf {5}, step_size {0.01};
    
    two_states_system(t0, tf, step_size); 
    return (0);
}

void two_states_system(double t0, double tf, double step_size)
{
    A.resize(2,2); A.Zero(2,2);
    B.resize(2,2); B.Zero(2,2);
    u.resize(2,1); u.Zero(2,1);
    x0.resize(2,1); x0.Zero(2,1);
    
    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    runge_kutta_dopri5<Eigen::Matrix<double, 2, 1>, double, Eigen::Matrix<double, 2, 1>, double, vector_space_algebra> stepper;
    
    integrate_const(stepper, state_function<Eigen::Matrix<double, 2, 1>>, x0, t0, tf, step_size, write_states<Eigen::Matrix<double, 2, 1>>);
}

void three_states_system(double t0, double tf, double step_size)
{
    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    runge_kutta_dopri5<Eigen::Matrix<double, 3, 1>, double, Eigen::Matrix<double, 3, 1>, double, vector_space_algebra> stepper;
    
    integrate_const(stepper, state_function<Eigen::Matrix<double, 3, 1>>, x0, t0, tf, step_size, write_states<Eigen::Matrix<double, 3, 1>>);
}

void four_states_system(double t0, double tf, double step_size)
{
    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    runge_kutta_dopri5<Eigen::Matrix<double, 4, 1>, double, Eigen::Matrix<double, 4, 1>, double, vector_space_algebra> stepper;
    
    integrate_const(stepper, state_function<Eigen::Matrix<double, 4, 1>>, x0, t0, tf, step_size, write_states<Eigen::Matrix<double, 4, 1>>);
}

void five_states_system(double t0, double tf, double step_size)
{
    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    runge_kutta_dopri5<Eigen::Matrix<double, 5, 1>, double, Eigen::Matrix<double, 5, 1>, double, vector_space_algebra> stepper;
    
    integrate_const(stepper, state_function<Eigen::Matrix<double, 5, 1>>, x0, t0, tf, step_size, write_states<Eigen::Matrix<double, 5, 1>>);
}

void six_states_system(double t0, double tf, double step_size)
{
    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    runge_kutta_dopri5<Eigen::Matrix<double, 6, 1>, double, Eigen::Matrix<double, 6, 1>, double, vector_space_algebra> stepper;
    
    integrate_const(stepper, state_function<Eigen::Matrix<double, 6, 1>>, x0, t0, tf, step_size, write_states<Eigen::Matrix<double, 6, 1>>);
}
