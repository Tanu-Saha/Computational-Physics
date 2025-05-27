//Ψ100=1/sqrt(M_PI*pow(a,3)))*exp(-r/a) was given now find <r> And plot r vs Ψ100

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double a=0.53;
double f(double x)
{
  return (4/pow(a,3))*pow(x,3)*exp(-2*x/a);

}
double simp(double a,double b,double n)
{
    double I=0,J=0,d,A;
    d=(b-a)/n;
    int i;
    for(i=1;i<n;i+=2){I+=f(a+i*d);}
    for(i=2;i<n;i+=2){J+=f(a+i*d);}
    return A=(d/3)*(f(a)+f(b)+4*I+2*J);
}
int main()
{
    ofstream fout("ff.dat");
    cout<<simp(0,1000,100000)<<endl;
     for(double i=0;i<=10;i+=0.1)
     fout<<i<<"  "<<(1/sqrt(M_PI*pow(a,3)))*exp(-i/a)<<endl;

    return 0;
}

