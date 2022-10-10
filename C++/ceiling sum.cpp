#include<bits/stdc++.h>
using namespace std ;

#define  ff      first 
#define  ss      second
#define  ull     unsigned long long 
#define  mod     1000000007
#define  inf     1e18
#define  w(x)    int x;cin>>x;while(x--)
#define  f(x,y)  for( x=0;x<y;x++) 

int main(){
    w(t){
        double a,b, s1,s2;
        long long x;
        cin>>a>>b;
            s1=ceil((b-(a-1))/2)+ceil(((a-1)-a)/2);
            s2=ceil((b-(a+1))/2)+ceil(((a+1)-a)/2);
            // cout<<"i is "<<i<<" ";
            // cout<<"s1 is"<<s1<<"s2 is"<<s2<<endl;
            // maximum=ceil(s1)+ceil(s2);
            if(a==b){
                x=0;
            }
            else if(a>b){
                x=s1;
            }
            else{
                x=s2;
            }        cout<<x<<endl;
        }



 	return 0;
}