
//Radial equation of hydrogen for R21 were given now find the A by normalization and plot r vs cumulative probability of R21^2  and r vs probability density

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double a=0.53;
double f(double x)
{
  return (x*x*x*x)*exp(-x/a);
}
double simp(double a,double b,double n)
{
    double I=0,J=0,d,A;
    d=(b-a)/n;
    int i=0;
    for(i=1;i<n;i+=2){I+=f(a+i*d);}
    for(i=2;i<n;i+=2){J+=f(a+i*d);}
    return A=(d/3)*(f(a)+f(b)+4*I+2*J);
}
int main()
{
    ofstream fout("ff.dat");
     double c=1/sqrt(simp(0,1000,10000));
     for(double i=0;i<=10;i+=0.1)
     fout<<i<<"  "<<c*c*simp(0,i,1000)<<"  "<<a*i*exp(-i/2*a)<<endl;

    return 0;
}

