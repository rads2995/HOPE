// normal_distribution
#include <iostream>
#include <string>
#include <random>

int main() {
    constexpr int nrolls = 10000;  // number of experiments
    constexpr int nstars = 100;    // maximum number of stars to distribute

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(5.0,2.0);

    int p[10] = {};

    for (size_t i = 0; i < nrolls; ++i) {
        double number = distribution(generator);
        if ((number>=0.0)&&(number<10.0)) 
            ++p[int(number)];
    }

    std::cout << "normal_distribution (5.0,2.0):" << std::endl;

    for (int i=0; i<10; ++i) {
        std::cout << i << "-" << (i+1) << ": ";
        std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
    }

    return 0;
}
