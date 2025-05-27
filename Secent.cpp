#include<iostream> 
#include<cmath> 
using namespace std; 
double e=0.0001; 
double f(double x) 
{ 
return x*x-7*x+12; 
} 
void sec(double x1,double x2) 
{ 
double x0; 
if(f(x1)-f(x2)!=0) 
{ 
do{x0=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1)); x1=x2; 
x2=x0; 
if(f(1)-f(x2)==0) 
break; 
} 
while(abs(x2-x0)>=e); 
cout<<"the root "<<x0<<endl; 
} 
else 
cout<<"no solution"<<endl; 
} 
int main() 
{ 
sec(-2,4); 
return 0; 
}

