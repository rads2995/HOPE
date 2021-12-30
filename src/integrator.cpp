#include <integrator.hpp>

std::ofstream values("function_result.txt");

constexpr double sigma = 10.0;
constexpr double R = 28.0;
constexpr double b = 8.0 / 3.0;

// Define integrator.hpp nonlinear integration functions
void nonlinear_system(double m_t0, double m_tf, double m_step_size) {
    boost::numeric::odeint::runge_kutta_dopri5<function_type, double, function_type, double, boost::numeric::odeint::vector_space_algebra> stepper;
    boost::numeric::odeint::integrate_const(stepper, nonlinear_function, x0, m_t0, m_tf, m_step_size, write_nonlinear_results);
}

void nonlinear_function(const function_type &x, function_type &dxdt, double t) {
    dxdt[0] = sigma * (x[1] - x[0]);
    dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
    dxdt[2] = -b * x[2] + x[0] * x[1];
}

void write_nonlinear_results(const function_type &x, const double t) {
    values << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        values << x[i] << '\t';
    
    values << std::endl; 
}
