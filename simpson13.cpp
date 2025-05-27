#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x)
{
    return x*x;
}
double simp13(double a,double b,double n)
{
    double d,I=0,J=0,A;
    int i;
    d=(b-a)/n;
    for(i=1;i<n;i+=2)
    {
        I+=f(a+i*d);
    }
    for(i=2;i<n;i+=2)
    {
        J+=f(a+i*d);
    }
    A=(d/3)*(f(a)+f(b)+4*I+2*J);
    return A;

}
int main()
{
    ofstream fout("simp13.dat");
    for(double j=0;j<=10;j+=0.1)
    {fout<<j<<"  "<<simp13(0,j,1000)<<endl;}
    return 0;}

