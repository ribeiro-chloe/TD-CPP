#include "complex2D.h"
#include <cmath>

//Défaut
Complex2D::Complex2D():
re(0.0), img(0.0)
{
}

//2 valeurs
Complex2D::Complex2D(double a, double b):
re(a), img(b)
{
}

//1 valeur
Complex2D::Complex2D(double ab):
re(ab), img(ab)
{
}

//Copie
Complex2D::Complex2D(const Complex2D& complex):
re(complex.re), img(complex.img)
{
}

//Getters
double Complex2D::GetRe()const
{
    return re;
}

double Complex2D::GetImg()const
{
    return img;
}

//Setters
void Complex2D::SetRe(double a)
{
    re = a;
}

void Complex2D::SetImg(double b)
{
    img = b;
}

//Addition
Complex2D Complex2D::operator+(const Complex2D& c) const
{
    return Complex2D(re+c.re,img+c.img);
}

//Soustraction
Complex2D Complex2D::operator-(const Complex2D& c) const
{
    return Complex2D(re-c.re,img-c.img);
}

//Mult
Complex2D Complex2D::operator*(const Complex2D& c) const
{
    double re2 = re * c.re - img * c.img;
    double img2 = re * c.img + img * c.re;

    return Complex2D(re2, img2);
}

//Division
Complex2D Complex2D::operator/(const Complex2D& c) const
{
    double denominateur = c.re * c.re + c.img * c.img;

    double re2 = (re * c.re + img * c.img)/denominateur;
    double img2 = (img * c.re - re * c.img)/denominateur;

    return Complex2D(re2,img2);
}

//<
bool Complex2D::operator<(const Complex2D& c) const{
    double module = std::sqrt(re*re + img*img);
    double module2 = std::sqrt(c.re*c.re + c.img*c.img);

    return module < module2;
}

//>
bool Complex2D::operator>(const Complex2D& c) const{
    double module = std::sqrt(re*re + img*img);
    double module2 = std::sqrt(c.re*c.re + c.img*c.img);

    return module > module2;
}