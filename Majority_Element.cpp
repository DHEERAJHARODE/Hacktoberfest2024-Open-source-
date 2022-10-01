#include<iostream>
using namespace std;
int majority(int arr[],int n)
{
    int count=1,res=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[res])
            count++;
        else                                                    //find the candidate
            count--;
        if(count==0)
        {
            count=1;
            res=i;
        }
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[res])
            count++;
    }                                                                //checking the candidate
    if(count<=n/2)
        return -1;
    else
        return res;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<a[majority(a,n)];
}
