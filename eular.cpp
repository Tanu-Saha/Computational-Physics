#include<cmath>
#include<fstream>
using namespace std;
double f(double x,double t)
{
    return 2-exp(-4*t)-(2*x);
}
void EU(double n,double tf,double t0,double x0)
{
    ofstream fout("EU_ode.dat");
    double h=(tf-t0)/n;
    double x=x0;
    for(double t=t0;t<=tf;t+=h)
    {
        x=x+h*f(x,t);
    fout<<t<<"  "<<x<<endl;}
}
int main()
{
    EU(10000,5,0,1);
    return 0;
}

