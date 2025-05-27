#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
double pi(double N)
{
    double x,y,N0=0;
    srand(time(0));
    for(int i=1;i<=N;i++)
    {
        x=((double)rand()/(double)RAND_MAX);
        y=((double)rand()/(double)RAND_MAX);

        if(sqrt(x*x+y*y)<=1)
            N0++;
    }
    return 4*(N0/N);
}
int main()
{
    cout<<pi(100000000);
    return 0;
}

