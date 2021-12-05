// main.cpp: source file containing main function
#include "simulate_system.h"
#include "matrix_functions.h"

// Write states from simulation as columns on text file 
std::ofstream data("simulation_result.txt");

// Define global matrices 
state_type A, B, C, D, u, x0;

int main() 
{  
    double t0 {0}, tf {10}, step_size {0.01};
    unsigned int num_states {2};
   
    std::cout << "How many states in your system?" << std::endl;
    std::cout << "Number of states: ";
    std::cin >> num_states; 
    std::cout << std::endl;

    if (num_states == 1)
    {
        matrix_resize(A, x0, num_states);
        simulate_system<Eigen::Matrix<double, 1, 1>>(t0, tf, step_size); 
    }
    
    else if (num_states == 2)
    {
        matrix_resize(A, x0, num_states);
        simulate_system<Eigen::Matrix<double, 2, 1>>(t0, tf, step_size);
    }
    
    else if (num_states == 3)
    {
        matrix_resize(A, x0, num_states);
        simulate_system<Eigen::Matrix<double, 3, 1>>(t0, tf, step_size);
    }
    
    else if (num_states == 4)
    {
        matrix_resize(A, x0, num_states);
        simulate_system<Eigen::Matrix<double, 4, 1>>(t0, tf, step_size);
    }
    
    else if (num_states == 5)
    {
        matrix_resize(A, x0, num_states);
        simulate_system<Eigen::Matrix<double, 5, 1>>(t0, tf, step_size);
    }
    
    else if (num_states == 6)
    {
        matrix_resize(A, x0, num_states);
        simulate_system<Eigen::Matrix<double, 6, 1>>(t0, tf, step_size);
    }
    
    else
        std::cout << "Invalid value for number of states!" << std::endl;

    return (0);
}

template<typename T>
void simulate_system(double t0, double tf, double step_size)
{
    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    boost::numeric::odeint::runge_kutta_dopri5<T, double, T, double, boost::numeric::odeint::vector_space_algebra> stepper;
    boost::numeric::odeint::integrate_const(stepper, state_function<T>, x0, t0, tf, step_size, write_states<T>);
}

// Define template state function for various matrix sizes
template<typename T>
void state_function (const T &x, T &dxdt, double t)
{
    dxdt = A * x;// + B * u;
}

template<typename T>
void write_states (const T &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}
