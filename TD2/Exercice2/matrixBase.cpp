#include "matrixBase.h"
#include <cmath>

template <typename T>
MatrixBase<T>::MatrixBase(): rows(0), cols(0) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t r, size_t c, T value):
rows(r), cols(c), data(r, std::vector<T>(c, value)) {}

template <typename T>
void MatrixBase<T>::addElement(size_t r, size_t c, const T& value){
    if (r < rows ||c < cols){
        data[r][c] = value;
    }
}

template <typename T>
size_t MatrixBase<T>::getRows()const{
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols()const{
    return cols;
}

template <typename T>
void MatrixBase<T>::Display() const {
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            std::cout << data[i][j] << "\t";
        }
        std::cout << "\n";
    }
}


template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>(){}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t r, size_t c, T value): MatrixBase<T>(r, c, value){}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(const MatrixBase<T>& matrix){
    this->rows = matrix.getRows();
    this->cols = matrix.getCols();
    this->data.resize(this->rows, std::vector<T>(this->cols));
    for (size_t i = 0; i<this->rows;++i){
        for(size_t j = 0; j<this->cols; ++j){
            this->data[i][j] = matrix.getElement(i,j);
        }
    }
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& matrix) const{
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i<this->rows;++i){
        for(size_t j = 0; j<this->cols; ++j){
            result.data[i][j] = this->data[i][j] + matrix.data[i][j];
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& matrix) const{
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i<this->rows;++i){
        for(size_t j = 0; j<this->cols; ++j){
            result.data[i][j] = this->data[i][j] - matrix.data[i][j];
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& matrix) const{
    MatrixNumerical<T> result(this->rows, matrix.cols, T(0));
    for (size_t i = 0; i<this->rows;++i){
        for(size_t j = 0; j<this->cols; ++j){
            for(size_t k = 0; k<this->cols; ++k){
                result.data[i][j] = this->data[i][k] * matrix.data[k][j];
            } 
        }
    }
    return result;
}

