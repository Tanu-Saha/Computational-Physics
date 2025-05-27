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
int main()
{  ofstream fout("b.dat");
    for(double z=0;z<=20;z+=0.1)
    {
        fout<<z<<"  "<<bessel(z,0)<<"  "<<bessel(z,1)<<"  "<<bessel(z,2)<<"  "<<bessel(z,3)<<endl;
    }return 0;
}

