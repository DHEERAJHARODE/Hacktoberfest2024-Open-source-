class Solution {
public:
    int countPaths(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m || j == n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }


        //right
        int right = countPaths(m, n, i, j+1, dp);

        //down
        int down = countPaths(m, n, i+1, j, dp);


        dp[i][j] = right + down;

        return dp[i][j];

    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int> (n, -1));

        int i = 0;
        int j = 0;
        int cnt = 0;

        return countPaths(m, n, i, j, dp);

    }
};
