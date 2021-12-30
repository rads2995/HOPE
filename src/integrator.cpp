#include <integrator.hpp>

constexpr double sigma = 10.0;
constexpr double R = 28.0;
constexpr double b = 8.0 / 3.0;

// Define integrator.hpp nonlinear integration functions
void nonlinear_system(double m_t0, double m_tf, double m_step_size) {
    boost::numeric::odeint::runge_kutta_dopri5<Eigen::Matrix<double, 3, 1>, double, Eigen::Matrix<double, 3, 1>, double, boost::numeric::odeint::vector_space_algebra> stepper;
    boost::numeric::odeint::integrate_const(stepper, nonlinear_function, x0, m_t0, m_tf, m_step_size, write_nonlinear_results);
}

void nonlinear_function(const Eigen::Matrix<double, 3, 1> &x, Eigen::Matrix<double, 3, 1> &dxdt, double t) {
    dxdt[0] = sigma * (x[1] - x[0]);
    dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
    dxdt[2] = -b * x[2] + x[0] * x[1];
}

void write_nonlinear_results(const Eigen::Matrix<double, 3, 1> &x, const double t) {
    data << t << '\t';
    
    for (size_t i = 0; i < x.rows(); i++)
        data << x[i] << '\t';
    
    data << std::endl; 
}
