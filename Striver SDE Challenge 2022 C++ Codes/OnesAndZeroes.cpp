int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int z=0,v=0;
        for(int s=0;s<strs.size();s++){
            z=count(strs[s].begin(),strs[s].end(),'0');
            v=strs[s].size()-z;
            for(int i=m;i>=z;i--){
                for(int j=n;j>=v;j--){
                    dp[i][j] = max(dp[i][j], 1+dp[i-z][j-v]);
                }
            }
        }
        return dp[m][n];
    }