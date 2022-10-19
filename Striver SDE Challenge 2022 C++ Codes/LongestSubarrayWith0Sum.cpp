#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int zero[arr.size()];
    zero[0]=arr[0];
    for(int i=1;i<arr.size();i++)
        zero[i]=arr[i]+zero[i-1];
    if(zero[arr.size()-1]==0) return arr.size();
    int ans=0,j=1;
    for(int i=0;i<arr.size()-1;i++){
        if(zero[i]==0) ans=max(ans,i+1);
        for(int j=i+1;j<arr.size();j++)
            if(zero[j]-zero[i]==0) ans=max(ans,j-i);
    }
    return ans;
}