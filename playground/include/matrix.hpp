#ifndef HOPE_MATRIX_HPP_
#define HOPE_MATRIX_HPP_

#include <iostream>

template <typename T>
class Matrix {
private:
    int num_rows {};
    int num_columns {};
    T *ptr_matrix = nullptr;
public:
    Matrix();
    Matrix(int num_rows, int num_columns);
    ~Matrix();

    // Getters and Setters
    T *get_ptr_matrix();
    void set_ptr_matrix(T *ptr_matrix);
    
    // Matrix member functions
    void print();
    void scalar_multiplication(T scalar);
    void populate_matrix();
};

// Default constructor
template <typename T>
Matrix<T>::Matrix() {}

// Overloaded constructor
template <typename T>
Matrix<T>::Matrix(int num_rows, int num_columns) {
    
    this->num_rows = num_rows;
    this->num_columns = num_columns;

    ptr_matrix = new T[num_rows * num_columns];

    for (size_t i = 0; i < num_rows * num_columns; i++)
        *(ptr_matrix + i) = 0;
}

// Destructor
template <typename T>
Matrix<T>::~Matrix() {
    delete [] ptr_matrix;
}

// Getter
template <typename T>
T *Matrix<T>::get_ptr_matrix() {
    return (this->ptr_matrix);
}

// Setter
template <typename T>
void Matrix<T>::set_ptr_matrix(T *ptr_matrix) {
    (this->ptr_matrix) = ptr_matrix;
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
void Matrix<T>::scalar_multiplication(T scalar) {
    
    auto ptr_copy = ptr_matrix;  
    
    for (size_t i = 0; i < num_rows; i++) {
        for (size_t j = 0; j < num_columns; j++) {
            *ptr_matrix = *ptr_matrix * scalar;
            ptr_matrix++;
        }
    }
    ptr_matrix = ptr_copy;
}

// Populate components of matrix
template <typename T>
void Matrix<T>::populate_matrix() {
    
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
