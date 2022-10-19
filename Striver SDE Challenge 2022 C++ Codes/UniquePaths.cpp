#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, 1));
    dp[0][0]=1;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++)
            dp[i][j] = dp[i][j-1]+dp[i-1][j];
    }
    return dp[m-1][n-1];
}