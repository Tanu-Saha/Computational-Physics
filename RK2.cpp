#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x,double t)
{
    return 2-exp(-4*t)-(2*x);}
void RK2(double t0,double tf,double n,double x0)
{
    ofstream fout("2rk.dat");
    double x=x0;
    double h=(tf-t0)/n;
    double k1,k2;
    for(double t=t0;t<=tf;t+=h)
    {
        k1=h*f(x,t);
        k2=h*f(x+(k1*0.5),t+(h*0.5));
        x+=k2;
        fout<<t<<"  "<<x<<endl;
    }}
    int main()
    {
       RK2(0,3,100,1);
       return 0;
    }

