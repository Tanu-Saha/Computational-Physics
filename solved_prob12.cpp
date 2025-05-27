#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double trap(double(func)(double),double a,double b,double N)
{
    double d,sum=0,x=a;
    d=(b-a)/N;
    for(int i=1;i<N;i++)
    {
        sum+=2*(func)(a+i*d);
    }
    return d*0.5*((sum)+(func)(a)+(func)(b));
}
double c(double u)
{
    return cos(0.5*M_PI*u*u);
}
double s(double u)
{
    return sin(0.5*M_PI*u*u);
}
double Fr_cos(double u)
{
    return trap(c,0,u,1000);
}
double Fr_sin(double u)
{
    return trap(s,0,u,1000);
}
double diffr(double x)
{
    double u=x*0.8165;
    double a=(2*Fr_cos(u)+1)*(2*Fr_cos(u)+1);
    double b=(2*Fr_sin(u)+1)*(2*Fr_sin(u)+1);
    return 0.125*(a+b);
}
int main()
{
    ofstream fout("dff.dat");
    for(double x=-5;x<=5;x+=0.01)
    {
        cout<<x<<"  "<<diffr(x)<<endl;
    }
    return 0;}

