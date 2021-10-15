#include "matrix.hpp"

int main() {
    
    // x_dot = [A]{x} + [B]{u}
    //     y = [C]{x}
    // where u is considered a constant input

    int num_states{};
    std::cout << "How many states?: ";
    std::cin >> num_states;

    // Create the state matrices
    Matrix <double> A(num_states, num_states);
    Matrix <double> x(num_states, 1);
    Matrix <double> B(num_states, 1);
    Matrix <double> C(1, num_states);
    
    // Populate the state matrices
    std::cout << "Components of matrix A:" << std::endl;
    A.populate_matrix();
    std::cout << "Components of matrix B:" << std::endl;
    B.populate_matrix();
    std::cout << "Components of matrix C:" << std::endl;
    C.populate_matrix();

    // TEST: print components for all matrices
    std::cout << "Matrix A: " << std::endl;
    A.print();
    std::cout << "Matrix B: " << std::endl;
    B.print();
    std::cout << "Matrix C: " << std::endl;
    C.print();

    // matrix_col_vector_multiplication(Ax, A, x);
    
    return 0;
}
