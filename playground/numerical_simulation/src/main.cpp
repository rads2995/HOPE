#include "simulate_system.h"

int main() {
    
    std::array <double, 3> x0 = {10.0, 1.0, 1.0};
    boost::numeric::odeint::integrate (equation, x0, 0.0, 50.0, 0.01, output);
    return 0;
}
