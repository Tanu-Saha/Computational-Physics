#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double g=9.8,l=1;
double f1(double t,double x,double v)
{
    return v;
}
double f2(double t,double x,double v)
{
    return (-g/l)*x;
}
void cromer2(double t0,double tf,double x0,double v0)
         {
             ofstream fout("ran.dat");
             double k1,l1,s1=x0,s2=v0;
             double h=0.01;
             for(double t=t0;t<=tf;t+=h)
             {

                 l1=h*f2(t,s1,s2);
                 s2+=(l1);
                 k1=h*f1(t,s1,s2);
                 s1+=(k1);
                fout<<t<<"  "<<s1<<"  "<<s2<<endl;
             }
         }
int main()
{
    cromer2(0,10,0,1);
    return 0;
}

