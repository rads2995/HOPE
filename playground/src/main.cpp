#include "matrix.hpp"

int main() {
    
    int num_states{};
    std::cout << "How many states?: ";
    std::cin >> num_states;

    Matrix <double> A(num_states, num_states);
    Matrix <double> B(num_states, 1);
    Matrix <double> C(1, num_states);
    
    std::cout << "Matrix A: " << std::endl;
    A.print();
    std::cout << "Matrix B: " << std::endl;
    B.print();
    std::cout << "Matrix C: " << std::endl;
    C.print();

    return 0;
}
