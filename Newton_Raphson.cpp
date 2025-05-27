#include<iostream> 
#include<cmath> 
using namespace std; 
double e=0.0001; 
double f(double x) 
{ 
return x*x-7*x+12; 
} 
double df(double x) 
{ 
return 2*x-7; 
} 
void NR(double x) 
{ 
double h=f(x)/df(x); 
while(abs(h)>=e) 
{ 
h=f(x)/df(x); 
x=x-h; 
} 
cout<<"the root "<<x<<endl; } 
int main() 
{ 
NR(6); 
return 0; 
}

