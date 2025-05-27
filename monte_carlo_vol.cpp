//Calculating volume of unit sphere : 

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
double vol(double N)
{
    double x,y,z,N0=0;
    srand(time(0));
    for(int i=1;i<=N;i++)
    {
        x=((double)rand()/(double)RAND_MAX);
        y=((double)rand()/(double)RAND_MAX);
        z=((double)rand()/(double)RAND_MAX);
        if(sqrt(x*x+y*y+z*z)<=1)
            N0++;
    }
    return 8*(N0/N);
}
int main()
{
cout<<vol(100000000);
    return 0;
}

