//Problem link: https://www.codechef.com/problems/BLACKCEL

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        int arr[101];
        int n,p,x,y;
        cin>>n>>p>>x>>y;
        int time=0;
        for(int j=0;j<n;++j)
        {
            cin>>arr[j];
        }
        for(int j=0;j<p;++j)
        {
            if(arr[j]==0)
            {
                time+=x;
            }
            else
            {
                time+=y;
            }
        }
        cout<<time<<endl;
    }
}
