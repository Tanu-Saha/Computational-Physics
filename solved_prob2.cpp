For uncertainty 
#include<iostream>
#include<cmath>
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
   return (x*x)*pow(a*hermite(x,n)*exp(-(x*x)/2),2);

}

double simp13(double a,double b,double n)
{
    double d,I=0,J=0,Area;
    d=(b-a)/n;
    int i;
    for(i=1;i<n;i+=2)
    {I+=f(a+i*d,5);}
    for(i=2;i<n;i+=2)
    {J+=f(a+i*d,5);
}
    Area=(d/3)*(f(a,5)+f(b,5)+4*I+2*J);
    return Area;
}
int main()
{
    cout<<sqrt(simp13(-100,100,1000000))<<endl;
    return 0;}

