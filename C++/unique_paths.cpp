class Solution {
public:
    
    int recur(int i, int j, vector<vector<int>> &dp)
    {
        // base case 
        if(i==0 && j==0)
        {
            return 1;
        }
        else if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int up = recur(i-1, j, dp );
        int left = recur(i, j-1, dp);
        
        return dp[i][j] = up+left;
    }
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return recur(m-1, n-1, dp);
        
        // int dp[m][n];
        vector<int>prev(n,0);
        for(int i =0; i<m; i++)
        {
            vector<int>curr(n,0);
            for(int j =0; j<n; j++)
            {
                if(i==0 && j==0)
                {
                    curr[j]=1;
                }
                else
                {
                    int up =0, left =0;
                    if(i>0)
                    {
                        up = prev[j];
                    }
                    if(j>0)
                    {
                        left = curr[j-1];
                    }
                    curr[j]= up+left;
                }
            }
            prev=curr;
        }
        return prev[n-1];
        
    }
};
