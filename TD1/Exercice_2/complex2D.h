#ifndef COMPLEX2D_H
#define COMPLEX2D_H
#include <iostream>

class Complex2D
{
    public:
        //Défaut
        Complex2D();
        //2 valeurs
        Complex2D(double a,double b);
        //1 valeur
        Complex2D(double ab);
        //Constructeur copie
        Complex2D(const Complex2D& complex);

        void SetRe(double a);
        void SetImg(double b);
        double GetRe() const;
        double GetImg() const;

        Complex2D operator +(const Complex2D& c) const;
        Complex2D operator-(const Complex2D& c) const;
        Complex2D operator*(const Complex2D& c) const;
        Complex2D operator/(const Complex2D& c) const;
        bool operator<(const Complex2D& c) const;
        bool operator>(const Complex2D& c) const;


    
    private:
        double re;
        double img;
};
        

#endif