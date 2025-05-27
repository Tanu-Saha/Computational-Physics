//Some solved problems
//Harmonic oscillator : quantum wave function using hermite polynomials.
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double hermite(double x,int n)
{
    if(n==0) return 1;
    else if(n==1) return 2*x;
    else return (2*x)*hermite(x,n-1)-2*(n-1)*hermite(x,n-2);

}
double fact(int n)
{
    if(n>0)
        return n*fact(n-1);
    else return 1;
}
double f(double x,int n)
{
    double a=1/(sqrt(pow(2,n)*fact(n)*sqrt(M_PI)));
   return a*hermite(x,n)*exp(-(x*x)/2);
}
int main()
{
    ofstream fout("hermite.dat");
for(double j=-6;j<=6;j+=0.1)
   fout<<j<<"  "<<f(j,0)<<"  "<<f(j,1)<<"  "<<f(j,2)<<"  "<<f(j,3)<<"  "<<f(j,4)<<"  "<<f(j,5)<<endl;
    return 0;}

