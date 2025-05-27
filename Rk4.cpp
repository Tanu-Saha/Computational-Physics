//SHM F=-kx/m where k=150,m=5, t0=0,x(t=0)=0.5, v(t=0)=4; using RK4
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double k=150,m=5;
double f1(double t,double x,double v)
{
    return v;
}
double f2(double t,double x,double v)
{
    return (-k*x)/m;
}
void rk4(double t0,double tf,double x0,double v0)
         {
             ofstream fout("SHM.dat");
             double k1,k2,k3,k4,l1,l2,l3,l4,s1=x0,s2=v0;
             double h=0.01;
             for(double t=t0;t<=tf;t+=h)
             {
                 k1=h*f1(t,s1,s2);
                 l1=h*f2(t,s1,s2);
                 k2=h*f1(t+(h*0.5),s1+(k1*0.5),s2+(l1*0.5));
                 l2=h*f2(t+(h*0.5),s1+(k1*0.5),s2+(l1*0.5));
                 k3=h*f1(t+(h*0.5),s1+(k2*0.5),s2+(l2*0.5));
                 l3=h*f2(t+(h*0.5),s1+(k2*0.5),s2+(l2*0.5));
                 k4=h*f1(t+h,s1+k3,s2+l3);
                 l4=h*f2(t+h,s1+k3,s2+l3);
                 s1+=(k1+2*k2+2*k3+k4)/6;
                 s2+=(l1+2*l2+2*l3+l4)/6;
                fout<<t<<"  "<<s1<<"  "<<s2<<endl;
             }
         }
         int main()
         {
             rk4(0,10,0.5,4);
             return 0;
         }

