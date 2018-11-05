#ifndef COMPLEX_H
#define COMPLEX_H
#include <math.h>
class Complex
{
private:
    double Real, Imaginar;
public:
    Complex();
    Complex(double, double);
    Complex(Complex&);
    double getReal()const {return Real;} ///metode de setat si furnizat
    double getImaginar()const {return Imaginar;}
    void setReal(double Re){Real = Re;}
    void setImaginar(double Im){Imaginar = Im;}
    void Citire();
    void Afisare();

    friend Complex operator+(const Complex& x);
    friend Complex operator+(const Complex& x, const Complex& y);
    friend Complex operator+(const Complex& x, const double y);
    friend Complex operator+(const double x, const Complex&y);

    friend Complex operator-(const Complex x);
    friend Complex operator-(const Complex& x, const Complex& y);
    friend Complex operator-(const Complex& x, const double y);
    friend Complex operator-(const double x, const Complex& y);

    friend Complex operator*(const Complex& x, const Complex& y);
    friend Complex operator*(const Complex& x, const double y);
    friend Complex operator*(const double x, const Complex& y);

    friend Complex operator/(const Complex& x, const Complex&y);
    friend Complex operator/(const Complex& x, const double y);
    friend Complex operator/(const double x, Complex& y);

    friend Complex& operator+=(Complex& x, const Complex& y);
    friend Complex& operator+=(Complex& x, const double y);

    friend Complex& operator-=(Complex& x, const Complex &y);
    friend Complex& operator-=(Complex& x, const double y);

    friend Complex& operator*=(Complex& x, const Complex &y);
    friend Complex& operator*=(Complex& x, const double y);

    friend Complex& operator/=(Complex& x, Complex &y);
    friend Complex& operator/=(Complex& x, const double y);

    friend bool operator==(const Complex& x, const Complex &y);
    friend bool operator==(const Complex& x, const double y);
    friend bool operator==(const double x, const Complex& y);

    friend bool operator!=(const Complex& x, const Complex &y);
    friend bool operator!=(const Complex& x, const double y);
    friend bool operator!=(const double x, const Complex& y);

    friend Complex operator^(Complex& x, int n);

    friend double abs(Complex& x)
    {
        double re = x.getReal()*x.getReal();
        double im = x.getImaginar()*x.getImaginar();
        return sqrt(re + im );
    }
    friend Complex sqrt( Complex& y)
    {
        Complex z;
        double re = sqrt((y.getReal() + abs(y)) / 2);
        double im;
        if(y.getImaginar()<0)
            im = (-1)*sqrt((-(y.getReal()) + abs(y)) / 2);
        else
            im = sqrt((-(y.getReal()) + abs(y)) / 2);
            z.Real=re;
            z.Imaginar=im;
        return z;
    }


};

#endif // COMPLEX_H
