Monte carlo integration for a function:

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
double f(double x)
{
    return x*x*x;
}
double MC(double a,double b,double c,double d,double N)
{
    double x,y,N0=0;
    srand(time(0));
    for(int i=1;i<N;i++)
    {
        x=a+(b-a)*((double)rand()/(double)RAND_MAX);
         y=c+(d-c)*((double)rand()/(double)RAND_MAX);
         if(y<=f(x))
         N0++;}
    return (N0/N)*(b-a)*(d-c);
    }
    int main()
    {
        cout<<MC(0,1,0,1,10000000)<<endl;
        return 0;
    }

