#ifndef matrixBase_h
#define matrixBase_h
#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class MatrixBase {
    protected:
        std::vector<std::vector<T>> data;
        size_t rows;
        size_t cols;

    public:
        

        MatrixBase();
        MatrixBase(size_t r, size_t c, T value = T());

        void addElement(size_t r, size_t c, const T& value);
        float getElement(size_t r, size_t c)const;

        size_t getRows() const;
        size_t getCols() const;

        virtual void Display() const;

};

template <typename T>
class MatrixNumerical :public MatrixBase<T>{
    public:
        MatrixNumerical();
        MatrixNumerical(size_t r, size_t c, T value = T());
        MatrixNumerical(const MatrixBase<T>& matrix);

        // T getDeterminant() const;

        MatrixNumerical operator+(const MatrixNumerical& matrix)const;
        MatrixNumerical operator-(const MatrixNumerical& matrix)const;
        MatrixNumerical operator*(const MatrixNumerical& matrix)const;
};

#include "matrixBase.cpp"


#endif