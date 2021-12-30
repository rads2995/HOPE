#include <iostream>
#include <cstdlib>
#include <cmath>

// Function declarations
double f (const double& x, const double& y);
void integrate ();

// Main function
int main() {
    
    integrate();
    return 0;
}

// Function definitions
double f (const double& x, const double& y) {
    double numerator = exp(-2*x - 3*y);
    double denominator = sqrt(x*x + y*y + 1);
    double result = numerator / denominator;
    return result;
}

void integrate () {
    // Declare and define local constants and variables
    constexpr double area {atan(1)};    // pi/4
    int n {0};
    double sum {0}, x {0}, y {0};

    // Seed random number generator
    srand(time(nullptr));

    // Obtain value of n
    std::cout << "Please provide value for N: ";
    std::cin >> n;

    // Loop for the value of n
    for (size_t i = 0; i < n; i++) {
        while (true) {
            // Generate random points between 0 and 1
            x = static_cast<double>(rand()) / RAND_MAX;
            y = static_cast<double>(rand()) / RAND_MAX;

            // Check if points are suitable
            if ((x*x + y*y) <= 1)
                break;
        }
    }

    // Update our sum with the given points
    sum = sum + f(x,y);

    // Integral: area times mean value <f> of f
    sum = area * sum / n;

    std::cout << "The integral is: " << sum << std::endl;
}
