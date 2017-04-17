fileheader

Firstnamespace.h

namespace Numbers {
    
    struct Rational{
        int numerator;
        int denominator;
        
        Rational(int num=0, int den=1);
    };
    

    Rational add(Rational a, Rational b);

    Rational sub(Rational a, Rational b);

    Rational mul(Rational a, Rational b);
    
    int mcm(int a,int b);

    std::ostream & operator<<(std::ostream & s, Rational & r);//V
}



/*------------file cpp---------------*/



Firstnamespace.cpp

#include<iostream>
#include "Firstnamespace.h"

using namespace std;

namespace Numbers {   
    
     Rational::Rational(int num, int den){
         numerator=num;
         denominator=den;
     }
    
    Rational add(Rational a, Rational b){
         
         int denominatore=mcm(a.denominator,b.denominator);
         int numeratore=((denominatore/a.denominator)*a.numerator)+((denominatore/b.denominator)*b.numerator);
         a.numerator=numeratore;
         a.denominator=denominatore;
         return a;
     }
     
     Rational sub(Rational a, Rational b){
         
         int denominatore=mcm(a.denominator,b.denominator);
         int numeratore=((denominatore/a.denominator)*a.numerator)-((denominatore/b.denominator)*b.numerator);
         a.numerator=numeratore;
         a.denominator=denominatore;
         return a;
         
     }
     
     Rational mul(Rational a, Rational b){
         
         int denominatore=a.denominator*b.denominator;
         int numeratore=a.numerator*b.numerator;
         a.numerator=numeratore;
         a.denominator=denominatore;
         return a;
     }
     
     std::ostream &operator<<(std::ostream &s, Rational &r){
         return s <<r.numerator<<"/"<<r.denominator<<" ";
     }
}



/*------------main---------------*/


#include <iostream>
#include "Firstnamespace.cpp"

using namespace std;
using namespace Numbers;

int main() 
{
    Rational x(3,7);
    x=sub(x,a);
	cout<<x<<endl;
}


