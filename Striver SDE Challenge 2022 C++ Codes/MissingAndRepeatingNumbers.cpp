#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int t_xor=0;
    //the xor of such arr is the ans we get by xor-ing missing and repeating nos
    for(int i=0;i<n;i++){
        t_xor = t_xor ^ arr[i];
        t_xor = t_xor ^ (i+1);
    }
    int x=0,y=0;
    int setbitinxor= t_xor & ~(t_xor-1);
    //dividing in two buckets with same pos set bit =0 or 1
    for(int i=0;i<n;i++){
        if(arr[i] & setbitinxor)
            x = x ^ arr[i];
        else 
            y = y ^ arr[i];
    }
    //re-xor the bucket nos so as to cancel same nos and finlly x and y would cotain ans
    for(int i=1;i<=n;i++){
        if(i & setbitinxor)
            x = x ^ i;
        else
            y = y ^ i;
    }
   //now we dont know either repeating or missing is in x or y, so we check the count of either of them in orginal arr
    int cx=0;
    for(int i=0;i<n;i++){
        if(arr[i]==x)
            cx++;
    }
    if(cx==0)//this was the missing no
        return {x,y};
    else return {y,x};
}
