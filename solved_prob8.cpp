#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double m,n;
double f(double x)
{
   return (2/sqrt(M_PI))*exp(-x*x);

}
double simp13(double a,double b,double n)
{
    double I=0,J=0,A,d;
    d=(b-a)/n;
    int i;
    for(i=1;i<n;i+=2){I+=f(a+i*d);}
    for(i=2;i<n;i+=2){J+=f(a+i*d);}
    return A=(d/3)*(f(a)+f(b)+4*I+2*J);
}
int main()
{
    ofstream fout("h.dat");
    for(double i=-2;i<=2;i+=0.1)
    fout<<i<<"  "<<simp13(0,i,10000)<<endl;
    return 0;
}

