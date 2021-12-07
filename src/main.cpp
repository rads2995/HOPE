// main.cpp: source file containing main function
#include "simulate_system.h"
#include "matrix_functions.h"

// Define data files for states and output from simulation  
std::ofstream data("simulation_result.txt");
std::ofstream output("output_result.txt");

// Define global matrices and vectors 
state_type A, B, C, D, u, x0, y;

int main() 
{  
    // Define initial time, final time, step size
    // and number of states for numerical integration
    double t0 {0}, tf {5}, step_size {0.1};
    unsigned int select {0}, num_states {0};
  
    std::cout << "\nWelcome to the LTI state-space system numerical simulator" << std::endl;
    std::cout << std::endl;
    
    while (1)
    {
        std::cout << "=================================" << std::endl;
        std::cout << "Numerical integration parameters:" << std::endl;
        std::cout << "=================================" << std::endl;
        std::cout << "Number of state variables: " << num_states << std::endl;
        std::cout << "Initial simulation time: " << t0 << " [s]" << std::endl;
        std::cout << "Final simulation time: " << tf << " [s]" << std::endl;
        std::cout << "Simulation step-size: " << step_size << " [s]" << std::endl;
        std::cout << "=================================" << std::endl;
       
        std::cout << "1. Modify number of state space variables" << std::endl;
        std::cout << "2. Modify numerical integration paremeters" << std::endl;
        std::cout << "3. Read matrices from data directory and run simulation" << std::endl;
        std::cout << "4. Exit program" << std::endl;
        std::cout << "Please enter your selection: ";
        std::cin >> select; std::cout << std::endl;

        // Switch statement for main menu selection
        switch (select) 
        {
            case 1:
                std::cout << "How many state variables in your system?" << std::endl;
                std::cout << "Number of state variables: ";
                std::cin >> num_states; std::cout << std::endl;
                break;

            case 2:
                std::cout << "Please enter the new numerical integration parameters." << std::endl;
                std::cout << "Initial simulation time (seconds): "; std::cin >> t0;
                std::cout << "Final simulation time (seconds): "; std::cin >> tf;
                std::cout << "Simulation step-size (seconds): "; std::cin >> step_size;
                std::cout << std::endl;
                break;

            case 3:
                
                // Automatic switch statement based on number of state variables
                matrix_read(A, B, C, D, u, x0);
                
                switch(num_states)
                {
                    case 1:
                        simulate_system<Eigen::Matrix<double, 1, 1>>(t0, tf, step_size);
                        std::cout << "Simulation completed!" << std::endl;
                        std::cout << std::endl;
                        break;
                
                    case 2:
                        simulate_system<Eigen::Matrix<double, 2, 1>>(t0, tf, step_size);
                        std::cout << "Simulation completed!" << std::endl;
                        std::cout << std::endl;
                        break;
            
                    case 3:
                        simulate_system<Eigen::Matrix<double, 3, 1>>(t0, tf, step_size);
                        std::cout << "Simulation completed!" << std::endl;
                        std::cout << std::endl;
                        break;
            
                    case 4:
                        simulate_system<Eigen::Matrix<double, 4, 1>>(t0, tf, step_size);
                        std::cout << "Simulation completed!" << std::endl;
                        std::cout << std::endl;
                        break;
            
                    case 5:
                        simulate_system<Eigen::Matrix<double, 5, 1>>(t0, tf, step_size);
                        std::cout << "Simulation completed!" << std::endl;
                        std::cout << std::endl;
                        break;
            
                    case 6:
                        simulate_system<Eigen::Matrix<double, 6, 1>>(t0, tf, step_size);
                        std::cout << "Simulation completed!" << std::endl;
                        std::cout << std::endl;
                        break;
            
                    default:
                        std::cout << "Error: invalid number of state variables!" << std::endl;
                        std::cout << std::endl;
                        break;
                } break;
            
            case 4:
                return (0);

            default:
                std::cout << "Error: invalid selection from menu." << std::endl;
                break;
        }
    }
    return (0);
}

template<typename T>
void simulate_system(double t0, double tf, double step_size)
{
    // Define stepper type as Runge-Kutta Dormand-Prince 5 method
    boost::numeric::odeint::runge_kutta_dopri5<T, double, T, double, boost::numeric::odeint::vector_space_algebra> stepper;
    boost::numeric::odeint::integrate_const(stepper, state_function<T>, x0, t0, tf, step_size, write_states<T>);
}

template<typename T>
void state_function (const T &x, T &dxdt, double t)
{
    // Solve differential equation of state-space system
    dxdt = A * x;// + B * u;
    
    // Solve output equation of state-space system
    //y = C * x + D * u;

    // Write output equation at current step 
    //write_output<T>(y);
}

template<typename T>
void write_states (const T &x, const double t)
{
    data << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}

template<typename T>
void write_output (const T &y)
{
    for (size_t i = 0; i < y.rows(); i++)
        output << y[i] << '\t';
    
    output << std::endl; 
}
