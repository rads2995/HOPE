#ifndef HOPE_MATRIX_HPP_
#define HOPE_MATRIX_HPP_

#include <iostream>

template <typename T>
class Matrix {
private:
    int num_rows {};
    int num_columns {};
    int num_elements {};
    T *ptr_matrix = nullptr;
public:
    Matrix();
    Matrix(int num_rows, int num_columns);
    ~Matrix();

    // Matrix member functions
    void print();
    void scalar_multiplication(Matrix<T>& matrix, T scalar);
    void matrix_multiplication(Matrix<T>& first_matrix, Matrix<T>& second_matrix);
    void populate_matrix(Matrix<T>& matrix);
};

// Default constructor
template <typename T>
Matrix<T>::Matrix() {}

// Overloaded constructor
template <typename T>
Matrix<T>::Matrix(int num_rows, int num_columns) {
    
    this->num_rows = num_rows;
    this->num_columns = num_columns;

    num_elements = num_rows * num_columns;

    ptr_matrix = new T[num_elements];

    for (size_t i = 0; i < num_elements; i++)
        *(ptr_matrix + i) = 0;
}

// Destructor
template <typename T>
Matrix<T>::~Matrix() {
    delete [] ptr_matrix;
}

// Print matrix to console
template <typename T>
void Matrix<T>::print() {
    
    auto ptr_copy = ptr_matrix;  
    
    for (size_t i = 0; i < num_rows; i++) {
        for (size_t j = 0; j < num_columns; j++) {
            std::cout << *ptr_matrix << "\t";
            ptr_matrix++;
        }
        std::cout << std::endl;
    }
    ptr_matrix = ptr_copy;
}

// Multiply matrix by scalar
template <typename T>
void Matrix<T>::scalar_multiplication(Matrix<T>& matrix, T scalar) {
    
    auto ptr_copy = ptr_matrix;  
    
    for (size_t i = 0; i < num_rows; i++) {
        for (size_t j = 0; j < num_columns; j++) {
            *ptr_matrix = *ptr_matrix * scalar;
            ptr_matrix++;
        }
    }
    ptr_matrix = ptr_copy;
}

// Resize matrix based on input
template <typename T>
void Matrix<T>::populate_matrix(Matrix<T>& matrix) {
    
    auto ptr_copy = ptr_matrix;
    T input{};

    for (size_t i = 0; i < num_rows; i++) {
        for (size_t j = 0; j < num_columns; j++) {
            std::cout << "Input for [" << i << "][" << j << "]: ";
            std::cin >> input;
            *ptr_matrix = input;
            ptr_matrix++;            
        }
    }
    ptr_matrix = ptr_copy;
}

#endif // HOPE_MATRIX_HPP_
