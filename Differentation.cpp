//differentiaion
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x)
{
    return exp(-2*x)*sin(3*x-1);
}
double df(double x,double h)
{
    double d=(f(x+h)-f(x-h))/2*h;
    return d;
}
int main()
{
    ofstream fout("t.dat");
    for(double i=0;i<=10;i+=0.1)
        fout<<i<<"   "<<df(i,0.1)<<endl;
    return 0;}

