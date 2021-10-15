#include "matrix.hpp"

int main() {
    
    // x_dot = [A]{x} + [B]{u}
    //     y = [C]{x}
    // where u is considered a constant input

    int num_states{3};
    std::cout << "How many states?: ";
    //std::cin >> num_states;

    // Create the state matrices
    Matrix <double> A(num_states, num_states);
    Matrix <double> x0(num_states, 1);
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

    // Populate the initial state
    std::cout << "Components of the initial state x0:" << std::endl;
    x0.populate_matrix();

    // matrix_col_vector_multiplication(Ax, A, x);
    Matrix <double> Ax(num_states, 1);
    Ax.matrix_multiplication(A, x0);
    Ax.print();
    
    return 0;
}
