#include "complex2D.h"
#include <iostream>

int main(){
    Complex2D c1(3,4);
    Complex2D c2(6,8);

    Complex2D c3 = c1 / c2;

    std::cout << "Re = "<< c3.GetRe() << std::endl;
    std::cout << "Img = "<< c3.GetImg() << std::endl;

    if(c1 < c2){
        std::cout <<"c1 plus petit que c2"<< std::endl;
    }
    else
    {
        std::cout <<"c1 pas plus petit que c2"<< std::endl;
    }
    
    return 0;
}