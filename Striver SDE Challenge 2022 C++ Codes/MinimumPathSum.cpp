//TABULATION 2D DP S(NM)
int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0) dp[i][j]=grid[i][j];
                else{
                    int up=grid[i][j];
                    if(i>0) up += dp[i-1][j];
                    else up+=1e9;
                    int left=grid[i][j];
                    if(j>0) left += dp[i][j-1];
                    else left+=1e9;
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }

//TAB 1D DP S(N+M)
int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<int> prev(n,0),cur(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0) cur[j]=grid[i][j];
                else{
                    int up=grid[i][j];
                    if(i>0) up += prev[j];
                    else up+=1e9;
                    int left=grid[i][j];
                    if(j>0) left += cur[j-1];
                    else left+=1e9;
                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[m-1];
    }