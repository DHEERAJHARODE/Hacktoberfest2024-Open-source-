#include <bits/stdc++.h> 
int maximumProfit(vector<int> &a){
    int i=0,j=1,maxi=0;
    while(j<a.size()){
        if(a[j]<=a[i]){
            i=j;
            j++;
        }
        else if(a[j]-a[i]>maxi){
            maxi=a[j]-a[i];
            j++;
        }
        else j++;
    }
    return maxi;
}