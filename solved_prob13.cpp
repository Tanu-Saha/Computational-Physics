#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else return n*fact(n-1);
}
double f(double z,int n,double theta)
{
    return (pow(z,n)/(pow(2,n+1)*fact(n)))*cos(z*cos(theta))*pow(sin(theta),(2*n)+1);
}
double bessel(double z, int n)
{
    double d,I=0;
    int N=200;
    d=M_PI/N;
    for(int i=1;i<=N;i++)
    {
        I+=f(z,n,i*d);
    }
    return (d/2)*(f(z,n,0)+f(z,n,M_PI)+2*I);
}
double f1(double z)
{
    return 0.5*bessel(z,0)*sqrt(z);
}
double fresnel(double x)
{
    double a,b=x;
    double d,I=0,J=0,A;
    int i;
    double n=1000;
    d=(b-a)/n;
    for(i=1;i<n;i+=2)
    {
        I+=f1(a+i*d);
    }
    for(i=2;i<n;i+=2)
    {
        J+=f1(a+i*d);
    }
    A=(d/3)*(f1(a)+f1(b)+4*I+2*J);
    return A;}
int main()
{     ofstream fout("f.dat");
        for(double j=0;j<=20;j+=0.1)
        fout<<j<<"  "<<fresnel(j)<<endl;
    return 0;
}

