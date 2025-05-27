// integration of sin(mx)sin(nx) over a period 0 to pi

#include<iostream>
#include<cmath>
using namespace std;
double m,n;
double f(double x)
{
   return sin(m*x)*sin(n*x);

}
double sim3(double a,double b,double n)
{
    double I=0,J=0,A,d;
     d=(b-a)/n;
    int i;
    for(i=1;i<n;i+=2){I+=f(a+i*d);}
    for(i=2;i<n;i+=2){J+=f(a+i*d);}
   return A=(d/3)*(f(a)+f(b)+4*I+2*J);
}
int main()
{
    cin>>m;
   cin>>n;
    cout<<sim3(0,2*M_PI,1000)<<endl;
    return 0;
}

