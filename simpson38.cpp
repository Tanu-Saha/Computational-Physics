#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x)
{
    return x*x*x;
}
double simp38(double a,double b,double n)
{
    double d,A,I=0,J=0,K=0;
    int i;
    d=(b-a)/n;
    for(i=1;i<n;i+=3){I+=f(a+i*d);}
    for(i=2;i<n;i+=3){J+=f(a+i*d);}
    for(i=3;i<n;i+=3){K+=f(a+i*d);}
    A=3*(d/8)*(f(a)+f(b)+3*(I+J)+2*K);
    return A;
}
int main()
{
    ofstream fout("simp38.dat");
    for(double j=0;j<=10;j+=0.1)
    {fout<<j<<"  "<<simp38(0,j,1000)<<endl;}
    return 0;
}

