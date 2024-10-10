import java.util.*;
class Solution {
    static int subset_sum(int[] arr,int n,int sum)
    {
        int mod= (int)1e9+7;
    int[][] dp = new int[n+1][sum+1];
    dp[0][0] = 1;
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
            if(i==0)
            dp[i][j]=0;
            else
            {
                if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) % mod;
            }
            else if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
                
            }
        }
    }
    return dp[n][sum];
    }
    public int findTargetSumWays(int[] nums, int target) {
        int d=target;
        int n=nums.length;
        int sum=(Arrays.stream(nums).sum());
        if(sum<d)
        return 0;
        if((sum-d)%2!=0)
        return 0;
        return subset_sum(nums,n,(sum-d)/2);
    }

}
