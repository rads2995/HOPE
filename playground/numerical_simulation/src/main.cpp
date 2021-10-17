#include "simulate_system.hpp"

int main() {
    
    state_type x = {10.0, 1.0, 1.0};
    integrate (lorenz, x, 0.0, 25.0, 0.1, write_lorenz);
    return 0;
}
