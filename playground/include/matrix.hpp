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

    int get_num_rows();
    int get_num_columns();
    int get_num_elements();
    T get_ptr_matrix();

    void set_num_rows(int num_rows);
    void set_num_columns(int num_columns);
    void set_num_elements(int num_elements);
    void set_ptr_matrix(T* ptr_matrix);    

    void print();
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
        *(ptr_matrix + i) = i;

    std::cout << "Matrix created!" << std::endl;
}

// Destructor
template <typename T>
Matrix<T>::~Matrix() {
    delete [] ptr_matrix;
    std::cout << "Matrix destroyed!" << std::endl;
}

// Getter functions
template <typename T>
int Matrix<T>::get_num_rows() {
    return this->num_rows;
}

template <typename T>
int Matrix<T>::get_num_columns() {
    return this->num_columns;
}

template <typename T>
int Matrix<T>::get_num_elements() {
    return this->num_elements;
}

template <typename T>
T Matrix<T>::get_ptr_matrix() {
    return this->ptr_matrix;
}

// Setter functions
template <typename T>
void Matrix<T>::set_num_rows(int num_rows) {
    this->num_rows = num_rows;
}

template <typename T>
void Matrix<T>::set_num_columns(int num_columns) {
    this->num_columns = num_columns;
}

template <typename T>
void Matrix<T>::set_num_elements(int num_elements) {
    this->num_elements = num_elements;
}

template <typename T>
void Matrix<T>::set_ptr_matrix(T* ptr_matrix) {
    this->ptr_matrix = ptr_matrix;
}

// Print matrix to console
template <typename T>
void Matrix<T>::print() {
    
    auto ptr_copy = ptr_matrix;  
    
    for (size_t i = 0; i < this->num_rows; i++) {
        for (size_t j = 0; j < this->num_columns; j++) {
            std::cout << *ptr_matrix << "\t";
            ptr_matrix++;
        }
        std::cout << std::endl;
    }
    ptr_matrix = ptr_copy;
}

template <typename T>
Matrix<T> scalar_multiplication(Matrix<T>& matrix, double scalar) {

    auto ptr_copy = matrix.get_ptr_matrix();  
    
    for (size_t i = 0; i < matrix.get_num_rows(); i++) {
        for (size_t j = 0; j < matrix.get_num_columns(); j++) {
            *matrix.set_ptr_matrix() = *(matrix.get_ptr_matrix()) * scalar;
            *matrix.set_ptr_matrix()++;
        }
    }
    
    matrix.ptr_matrix = ptr_copy;
    return matrix;
}

#endif // HOPE_MATRIX_HPP_
