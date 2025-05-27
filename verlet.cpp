#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double g=9.8,l=1;
double f2(double t,double x,double v)
{
    return (-g/l)*x;
}

void verlet(double t0,double tf,double x0,double v0)
{
    ofstream fout("verlet.dat");
    double x=x0, v=v0;
    double x_old;
    double h=0.01;
    for(double t=t0;t<=tf;t+=h)
    {
        x_old=x;
        fout<<t<<"  "<<x<<" "<<v<<endl;
        x+=(h*v)+(h*h/2)*f2(t,x,v);
        v+=(h/2)*f2(t,x_old,v)+f2(t,x,v);

    }
}
int main()
{
    verlet(0,10,0.5,0);
    return 0;
}

