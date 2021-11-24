#ifndef SIMULATE_SYSTEM_HPP
#define SIMULATE_SYSTEM_HPP

#include <fstream>
#include <Eigen/Core>
#include <boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <boost/numeric/odeint/integrate/integrate_const.hpp>

// Write results from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

// FLAG: do not re-enter values for matrix [A]
bool flag = true;

// Construct the equations of motion in state-space form for N-states
template<size_t N>
void ode_function (const Eigen::Matrix<double, N, 1> &x, Eigen::Matrix<double, N, 1> &dxdt, double t)
{   
    
    // TODO: Creation of matrix [A] should occur only once!!!
    Eigen::Matrix<double, N, N> A;
    
    /*
    std::array<std::array<double, N>, N> temp;
    std::cout << "\nEnter the values for matrix [A]: ";   
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            std::cin >> temp[i][j];
    
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            A(i,j) = temp[i][j];
    */    
    
    A << 0, 1, -0.5, -1;

    dxdt = A * x;
}

// Write the quations of motion states into the text file
// TODO: implement loop depending on number of states - Rodrigo
template<size_t N>
void write_states (const Eigen::Matrix<double, N, 1> &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < N; i++)
        data << x[i] << '\t';
    
    data << std::endl; 
    
    //data << t << '\t' << x[0] << '\t' << x[1] << '\t' << x[2] << std::endl;
}

#endif // SIMULATE_SYSTEM_HPP
