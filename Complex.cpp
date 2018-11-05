#include "Complex.h"
#include <iostream>
using namespace std;
Complex::Complex(){}

Complex::Complex(double Re, double Im)
{
    Real = Re;
    Imaginar = Im;
}

Complex::Complex(Complex &x)
{
    Real = x.getReal();
    Imaginar = x.getImaginar();
}

Complex operator+(const Complex &x)
{
    Complex z;
    z.Real=x.getReal();
    z.Imaginar=x.getImaginar();
    return z;
}

Complex operator+(const Complex& x, const Complex& y)
{
    Complex z;
    z.Real = x.getReal() + y.getReal();
    z.Imaginar= x.getImaginar() + y.getImaginar();
    return z;
}

Complex operator+(const Complex& x, const double y)
{
    Complex z;
    z.Real = x.getReal() + y;
    z.Imaginar = x.getImaginar();
    return z;
}

Complex operator+(const double x, const Complex& y)
{
    Complex z;
    z.Real = x + y.getReal();
    z.Imaginar = y.getImaginar();
    return z;
}


Complex operator-(const Complex x)
{
    Complex z;
    z.Real = x.getReal() *(-1);
    z.Imaginar = x.getImaginar()*(-1);
    return z;
}



Complex operator-(const Complex& x, const Complex& y)
{
    Complex z;
    z.Real = x.getReal() - y.getReal();
    z.Imaginar= x.getImaginar() - y.getImaginar();
    return z;
}

Complex operator-(const Complex& x, const double y)
{
    Complex z;
    z.Real = x.getReal() - y;
    z.Imaginar = x.getImaginar();
    return z;
}

Complex operator-(const double x, const Complex& y)
{
    Complex z;
    z.Real = x - y.getReal();
    z.Imaginar= y.getImaginar();
    return z;
}

Complex operator*(const Complex& x, const Complex& y)
{
    Complex z;
    double ac = y.getReal() * x.getReal();
    double bd = y.getImaginar() * x.getImaginar();
    double ad = y.getReal() * x.getImaginar();
    double bc = y.getImaginar() * x.getReal();
    z.Real=ac-bd;
    z.Imaginar=bc+ad;
    return z;
}

Complex operator*(const Complex& x, const double y)
{
    Complex z;
    z.Real = x.getReal() * y;
    z.Imaginar = x.getImaginar() * y;
    return z;
}

Complex operator*(const double x, const Complex& y)
{
    Complex z;
    z.Real = y.getReal() * x ;
    z.Imaginar = y.getImaginar() * x;
    return z;
}

Complex operator/(const Complex& x, const Complex& y)
{
    Complex z;
    z=y;
    if(y.getReal() == 0 && y.getImaginar() == 0)
    {
        cout<<"Nu se poate efectua impartirea la numarul ";
        return z;
    }
    else
    {
        double re = (x.getReal()*y.getReal()+x.getImaginar()*y.getImaginar())/(y.getReal()*y.getReal()+y.getImaginar()*y.getImaginar());
        double im = (x.getImaginar()*y.getReal()-x.getReal()*y.getImaginar())/(y.getReal()*y.getReal()+y.getImaginar()*y.getImaginar());
        z.Real=re;
        z.Imaginar=im;
        return z;
    }
}
Complex operator/(const Complex& x, const double y)
{
    Complex z;
    z=x;
    if(y == 0)
    {
        cout<<"Nu se poate efectua impartirea la 0 a numarului ";
        return z;
    }
    else
    {
        z.Real = x.getReal() / y;
        z.Imaginar = x.getImaginar() / y;
        return z;
    }
}

Complex operator/(const double x,  Complex &y)
{
    Complex z;
    z=y;
    if(y.getImaginar()==0 && y.getReal()==0)
    {
        cout<<"Nu se poate efectua impartirea la numarul ";
        return y;
    }
    else
    {
        z.Real=(x*y.getReal())/(y.getReal()*y.getReal()+y.getImaginar()*y.getImaginar());
        z.Imaginar=(-x*y.getImaginar())/(y.getReal()*y.getReal()+y.getImaginar()*y.getImaginar());
        return z;
    }
}

Complex &operator+=(Complex& x, const Complex& y)
{
    x.Real=x.getReal()+y.getReal();
    x.Imaginar=x.Imaginar+y.Imaginar;
    return x;
}

Complex &operator+=(Complex& x,const double y)
{
    x.Real=x.getReal()+y;
    return x;
}
Complex &operator-=(Complex& x, const Complex& y)
{
    x=x-y;
    return x;
}

Complex &operator-=(Complex &x,const double y)
{
    x=x-y;
    return x;
}
Complex& operator*=(Complex& x, const Complex& y)
{
    double ac = y.getReal() * x.getReal();
    double bd = y.getImaginar() * x.getImaginar();
    double ad = y.getReal() * x.getImaginar();
    double bc = y.getImaginar() * x.getReal();
    x.Imaginar=bc+ad;
    x.Real = ac-bd;
    return x;

}
Complex &operator*=(Complex& x,const double y)
{
    x.Real = x.getReal() * y;
    x.Imaginar= x.getImaginar() * y;
    return x;
}
Complex& operator/=(Complex& x, Complex& y)
{
    if(y.getReal() == 0 || y.getImaginar() == 0)
    {
        cout<<"Nu se poate efectua impartirea la numarul";
        return y;
    }
    else
    {
        double re = (x.getReal()*y.getReal()+x.getImaginar()*y.getImaginar())/(y.getReal()*y.getReal()+y.getImaginar()*y.getImaginar());
        double im = (x.getImaginar()*y.getReal()-x.getReal()*y.getImaginar())/(y.getReal()*y.getReal()+y.getImaginar()*y.getImaginar());
        x.Real=re;
        x.Imaginar=im;
        return x;
    }
}
Complex& operator/=(Complex& x, const double y)
{
    if(y == 0)
    {
        cout<<"Pentru numarul real dat nu se poate efectua impartirea numarului ";
        return x;
    }
    else
    {
        double re = x.getReal() / y;
        double im = x.getImaginar() / y;
        x.Imaginar=im;
        x.Real=re;
        return x;
    }

}

bool operator==(const Complex& x, const Complex& y)
{
    if(x.getReal()==y.getReal() && x.getImaginar()==y.getImaginar())
        return true;
    return false;
}

bool operator==(const Complex& x, const double y)
{
    if(x.getReal()==y && x.getImaginar()==0)
        return true;
    return false;
}

bool operator==(const double x, const Complex& y)
{
    if(y.getReal()==x && y.getImaginar()==0)
        return true;
    return false;
}
bool operator!=(const Complex& x, const Complex& y)
{
    if(x.getReal()!= y.getReal() || x.getImaginar() != y.getImaginar())
        return true;
    return false;
}
bool operator!=(const Complex& x, const double y)
{
    if(x.getReal() != y || x.getImaginar() != 0)
        return true;
    return false;
}
bool operator!=(const double x, const Complex& y)
{
    if(x!=y.getReal() || 0!=y.getImaginar())
        return true;
    return false;
}

Complex operator^(Complex& x, int n)
{
    int i;
    Complex aux;
    aux = x;
    if(n==0)
    {
        aux.Real = 1;
        aux.Imaginar = 0;
    }
    else
        for(i=1;i<n;i++)
            aux=x*aux;
    return aux;
}

void Complex::Citire()
{
    cout<<"Real: ";
    cin>>Real;
    cout<<"Imaginar: ";
    cin>>Imaginar;
    cout<<endl;
}

void Complex::Afisare()
{
    if (Real == 0)
    {
        if(Imaginar == 0)
            cout<<"0";
        else
            if(Imaginar == 1)
                cout<<"i";
            else
                if (Imaginar == -1)
                    cout<<"-i";
                else{
                    if(Imaginar > 0)
                        cout<<Imaginar<<"*i";
                    else
                        cout<<Imaginar<<"*i";
                }
    }
     else
        if(Real > 0)
        {
            if(Imaginar == 0)
            cout<<Real;
        else
            if(Imaginar == 1)
                cout<<Real<<"+i";
                else
                if (Imaginar == -1)
                    cout<<Real<<"-i";
                else{
                    if(Imaginar > 0)
                        cout<<Real<<"+"<<Imaginar<<"*i";
                    else
                        cout<<Real<<Imaginar<<"*i";
                }
        }
        else
        if(Real < 0)
        {
            if(Imaginar == 0)
            cout<<Real;
            else
            if(Imaginar == 1)
                cout<<Real<<"+i";
                else
                if (Imaginar == -1)
                    cout<<Real<<"-i";
                else{
                    if(Imaginar > 0)
                        cout<<Real<<"+"<<Imaginar<<"*i";
                    else
                        cout<<Real<<Imaginar<<"*i";
                }
        }
}


