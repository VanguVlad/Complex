#include <iostream>
#include "Complex.h"
#include <math.h>
using namespace std;
void meniu()
{
    cout<<"1.Aduna doua numere complexe."<<endl;
    cout<<"2.Scade doua numere complexe."<<endl;
    cout<<"3.Inmulteste doua numere complexe."<<endl;
    cout<<"4.Imparte doua numere complexe."<<endl;
    cout<<"5.Ridica la putere un numar complex."<<endl;
    cout<<"6.Modulul unui numar complex."<<endl;
    cout<<"7.Radicalul unui numar complex."<<endl;
    cout<<"8.Rezolva ecuatia de gradul 2 cu coeficienti complecsi."<<endl;
    cout<<"9.Iesire"<<endl;
    cout<<"Introduceti optiunea: ";
}
void ecuatie2()
    {
        Complex a,b,c,delta,x,x1,x2;
        cout<<"Coeficientul lui x^2: ";
        a.Citire();
        cout<<"Coeficientul lui x^1: ";
        b.Citire();
        cout<<"Coeficientul lui x^0: ";
        c.Citire();
        if(a==0)
            if(b==0)
                if(c==0)
                    cout<<"Ecuatia are o infinitate de solutii.";
                else
                    cout<<"Imposibil";
            else
            {
                cout<<"x = ";
                x = (-c)/b;
                x.Afisare();
            }
        else
        {
            cout<<"delta = ";
            delta=(b*b)-4*a*c;
            delta.Afisare();
            cout<<endl;
            if(delta == 0)
            {
                cout<<"x = ";
                x=(-b)/(2*a);
                x.Afisare();
                cout<<endl;
            }
            else
            {
                cout<<"x1 = ";
                x1 = (-b-sqrt(delta))/(2*a);
                x1.Afisare();
                x2 = (-b+sqrt(delta))/(2*a);
                cout<<endl<<"x2 = ";
                x2.Afisare();
            }
        }

    }
int main()
{
    int op,n,m;
    Complex a,b,c;
    meniu();
    cin>>op;
    switch(op)
    {
        case 1:
            cout<<"Introduceti primul numar complex: "; a.Citire();
            cout<<"Introduceti al doilea numar complex: "; b.Citire();
            a = a+b;
            cout<<"Rezultat: ";
            a.Afisare();
            break;
        case 2:
            cout<<"Introduceti primul numar complex: "; a.Citire();
            cout<<"Introduceti al doilea numar complex: "; b.Citire();
            a = a-b;
            cout<<"Rezultat: ";
            a.Afisare();
            break;
        case 3:
            cout<<"Introduceti primul numar complex: "; a.Citire();
            cout<<"Introduceti al doilea numar complex: "; b.Citire();
            a = a*b;
            cout<<"Rezultat: ";
            a.Afisare();
            break;
        case 4:
            cout<<"Introduceti primul numar complex: "; a.Citire();
            cout<<"Introduceti al doilea numar complex: "; b.Citire();
            a = a/b;
            a.Afisare();
            break;
        case 5:
            cout<<"Introduceti numarul complex: "; a.Citire();
            cout<<"Introduceti puterea: "; cin>>n;
            a = a^n;
            cout<<"Rezultat: ";
            a.Afisare();
            break;
        case 6:
            cout<<"Introduceti numarul complex: "; a.Citire();
            m = abs(a);
            cout<<"Modulul numarului "; a.Afisare(); cout<<" este "<<m;
            break;
        case 7:
            cout<<"Introduceti numarul complex: "; a.Citire();
            c = sqrt(a);
            cout<<"Rezultat: ";
            c.Afisare();
            break;
        case 8:
            ecuatie2();
            break;
        case 9:
            return 0;
        default: cout<<"Optiunea introdusa nu este valida!";
    }
    return 0;
}
