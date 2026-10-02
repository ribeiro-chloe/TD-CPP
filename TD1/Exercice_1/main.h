#ifndef MAIN_H
#define MAIN_H
#include <iostream>

//void print_str(std::string);

class my_class
{
    private:
        std::string str;
    public:
        void print_my_element(std::string);
        my_class();//constructeur par défaut
        my_class(std::string str1);//constructeur avec argument
}

#endif