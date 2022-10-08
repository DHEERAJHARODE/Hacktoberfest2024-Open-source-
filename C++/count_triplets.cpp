#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int count_triplet(int* a,int n)
{
    int count=0;
    unordered_map<int,int> umap;
    for (int i=0;i<n;i++)
    {
        umap.insert(make_pair(a[i],0));
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(umap.find(a[i]+a[j])!=umap.end())
                count+=1;
            else
                continue;
        }
    }
    return count;
}

bool triplet_exists(int* a, int i, int j, int s)
{
    int start = i;
    int end = j;
    while(start<end)
    {
        int sum = a[start]+a[end];
        if(sum==s)
            return true;
        else if(sum>s)
            end-=1;
        else
            start+=1;
    }
    return false;
}



int count_triplet_fast(int* a, int n)
{
    int count=0;
    sort(a,a+n);
    for(int i=n-1;i>1;i--)
    {
        if(triplet_exists(a,0,i-1,a[i]))
            count+=1;
        else
            continue;
    }
    return count;
}




int main()
{
    int *a;
    int n; 
    cin>>n;

    a = new int[n];

    for (int i =0;i<n;i++)
        cin>>a[i];
    
    cout<<count_triplet_fast(a,n);
    return 0;
}
