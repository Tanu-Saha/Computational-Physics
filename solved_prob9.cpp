//Normalize ψ(x)=A (sin⁡(x))/x dx and plot the state function x vs ψ(x).
//normalization and plotting the state function
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x)
{
    if(x==0){return 1;}
    else
        return (sin(x)*sin(x)/(x*x));
}

double simp13(double a,double b,double n,double(func)(double))
{
    double d,I=0,J=0,Area;
    d=(b-a)/n;
    int i;
    for(i=1;i<n;i+=2)
    {
        I+=f(a+i*d);
    }
    for(i=2;i<n;i+=2)
    {
        J+=f(a+i*d);
    }
    Area=(d/3)*(f(a)+f(b)+4*I+2*J);
    return Area;
}
int main()
{
    ofstream fout("sinc.dat");
    double sum=simp13(-100,100,100000,f);
    double A=(sqrt(1/(sum,2));
    for(double m=-30;m<=30;m+=0.1)
    fout<<m<<"  "<<A*(sin(m)/m)<<endl;
    return 0;
}

