//Normalize  ψ(x)=A(2*x^2-1)*exp(-0.5*x*x) find the value of A. and plot the state function and the normalized function with respect to x.
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x)
{

   return (2*x*x-1)*exp(-0.5*x*x);
}
double simp(double a,double b,double n)
{
    double I=0,J=0,K=0,A,d;
    int i;
    d=(b-a)/n;
    for(i=1;i<n;i+=3){I+=f(a+i*d);}
    for(i=2;i<n;i+=3){J+=f(a+i*d);}
    for(i=3;i<n;i+=3){K+=f(a+i*d);}
    return A=(3*d/8)*(f(a)+f(b)+3*I+3*J+2*K);
}
int main()
{
    ofstream fout("tt.dat");
    double a=1/sqrt(pow(simp(-100,100,1000000),2));
    cout<<a<<endl;
    for(double i=-10;i<10;i+=0.1)
        fout<<i<<"  "<<a*(2*i*i-1)*exp(-0.5*i*i)<<endl;
    return 0;
}

