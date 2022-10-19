#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int numRows) 
{
  vector<vector<long long int>> dp(numRows);
        for(int i=0;i<numRows;i++){
            dp[i]=vector<long long int>(i+1,1);
            for(int j=1;j<i;j++){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
        }
        return dp;
}
