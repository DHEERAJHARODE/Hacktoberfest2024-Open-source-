#include <iostream>
using namespace std;

void fib(int n)
{
 int t0=0,t1=1,s=0,i;
 
 if(n<=1) return ;
 
 for(i=2;i<=n;i++)
 {
    cout<<t1<<" ";
    s=t0+t1;
    t0=t1;
    t1=s;
 
 }
 
}

int main(){
    int n=7;
    fib(n);
    return 0; 
}