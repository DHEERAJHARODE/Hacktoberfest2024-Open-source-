#include <bits/stdc++.h> 
long long maxSubarraySum(int nums[], int n)
{
    long long maxx = nums[0];
    long long dp[n];
    dp[0] = nums[0];
    for(int i = 1; i<n; i++){
        if(nums[i]>nums[i]+dp[i-1])
            dp[i]=nums[i];
        else
            dp[i]=nums[i]+dp[i-1];
        if(maxx<dp[i])
            maxx=dp[i];
    }
    if(maxx>0) return maxx;
    else return 0;
}