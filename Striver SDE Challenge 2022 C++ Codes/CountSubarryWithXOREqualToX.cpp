#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int t)
{
    int c=0, xorr=0;
    unordered_map<int,int> umap; //pfxor and freq of subarr with that pfxor
    for(int i=0;i<arr.size();i++){
        xorr=xorr^arr[i];
        if(xorr==t) c++;
        int txor=xorr^t;
        if(umap.find(txor)!=umap.end())//subarr with xor=xorr exists
            c=c+umap[txor];
        umap[xorr]++;
    }
    return c;
}