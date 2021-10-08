#include<bits/stdc++.h>
using namespace std;
void factorial(int n)
{
    vector<int>v;
    int l=1,carry;
    v.push_back(1);
    for(int x=2;x<=n;x++)
    {
        carry=0;
        for(int i=0;i<l;i++)
        {
            int prod=v[i]*x+carry;
            v[i]=prod%10;
            carry=prod/10;
        }
        while(carry)
        {
            v.push_back(carry%10);
            carry/=10;
            l++;
        }
    }
    for(int i=l-1;i>=0;i--)
    cout<<v[i];
}
int main()
{
    int n=100;
    factorial(n);
    return 0;
    
}
