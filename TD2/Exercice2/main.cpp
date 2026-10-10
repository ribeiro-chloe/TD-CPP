#include "matrixBase.h"
#include <iostream>


int main(){
    MatrixNumerical<int> mat1(2,2,0);
    mat1.addElement(0,0,1);
    mat1.addElement(0,1,2);
    mat1.addElement(1,0,1);
    mat1.addElement(1,4,1);

    std::cout << "\nMatrice 1:\n";
    mat1.Display();

    MatrixNumerical<int> mat2(2,2,1);
    std::cout << "\nMatrice 2:\n";
    mat2.Display();

    std::cout << "\nAddition Matrice 1 et 2\n";
    MatrixNumerical<int> sum = mat1 + mat2;
    sum.Display();

    std::cout << "\nSoustraction Matrice 1 et 2\n";
    MatrixNumerical<int> sub = mat1 - mat2;
    sub.Display();

    std::cout << "\nMultiplication Matrice 1 et 2\n";
    MatrixNumerical<int> mult = mat1 * mat2;
    mult.Display();


}