#include <bits/stdc++.h> 
long getTrappedWater(long *height, int n){
    long ans=0,maxl=0,maxr=0,l=0,r=n-1;
    while(l<=r){
        if(height[l]<=height[r]){
            if(height[l]>=maxl) maxl=height[l];
            else ans+=maxl-height[l];
            l++;
        }
        else{
            if(height[r]>=maxr) maxr=height[r];
            else ans+=maxr-height[r];
            r--;
        }
    }
    return ans;
}