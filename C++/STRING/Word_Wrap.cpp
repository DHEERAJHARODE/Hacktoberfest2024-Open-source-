#include <bits/stdc++.h>
using namespace std;

int n;
int solve(vector<int> &nums, int k, int idx, vector<int> &dp){
    if (idx >= n){
        return 0;
    }
    if (dp[idx] != -1){
        return dp[idx];
    }
    int ans = INT_MAX;
    int sum = 0;
    for (int i = idx; i < n; i++){
        sum += nums[i];
        if (k >= sum && i == n - 1){
            ans = min(ans, solve(nums, k, i + 1, dp));
        }
        else if (k >= sum){
            int x = k - sum;
            x = x * x;
            ans = min(ans, x + solve(nums, k, i + 1, dp));
        }
        ++sum;
    }
    return dp[idx] = ans;
}
int solveWordWrap(vector<int> nums, int k){
    // Code here
    n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, k, 0, dp);
}

int main(){
    vector<int> nums = {3,2,2,5};
    int k = 6;
    cout << "Minimum cost: " << solveWordWrap(nums, k) << endl;
    return 0;
}