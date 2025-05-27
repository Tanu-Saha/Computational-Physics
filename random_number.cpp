//genareting 10 random numbers from -9 to 9

#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int i=0;
    while(i++<10)
    {
        int r=(rand()%19)+(-9);
        cout<<r<<endl;
    }
    return 0;
}

