#include "simulate_system.hpp"

int main() {
    
    std::array <double, 3> x = {10.0, 1.0, 1.0};
    boost::numeric::odeint::integrate (lorenz, x, 0.0, 25.0, 0.1, write_lorenz);
    return 0;
}
