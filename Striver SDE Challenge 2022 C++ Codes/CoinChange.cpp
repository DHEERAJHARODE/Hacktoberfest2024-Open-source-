//DP
int f(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0) return amt%coins[0]==0?amt/coins[0]:1e9;
        if(dp[ind][amt] != -1) return dp[ind][amt];
        int nottake = f(ind-1,amt,coins,dp);
        int take=INT_MAX;//since u want min
        if(coins[ind]<=amt) take = 1+f(ind,amt-coins[ind],coins,dp);
        return dp[ind][amt] = min(take,nottake);
    }
    
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        if(n==1) return amt%coins[0]==0?amt/coins[0]:-1;
        vector<vector<int>> dp(n, vector<int>(amt+1,-1));
        int ans = f(n-1,amt,coins,dp);
        if(ans>=1e9) return -1;
        else return ans;
    }

//TAB
int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        if(n==1) return amt%coins[0]==0?amt/coins[0]:-1;
        vector<vector<int>> dp(n, vector<int>(amt+1,-1));
        for(int j=0;j<=amt;j++) dp[0][j] = j%coins[0]==0?j/coins[0]:1e9;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                int nottake = dp[i-1][j];
                int take=INT_MAX;//since u want min
                if(coins[i]<=j) take = 1+dp[i][j-coins[i]];
                dp[i][j] = min(take, nottake);
            }
        }
        int ans = dp[n-1][amt];
        if(ans>=1e9) return -1;
        else return ans;
    }

//OPT TAB
int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        if(n==1) return amt%coins[0]==0?amt/coins[0]:-1;
//      -----------------------DND-----------------------
        vector<int> prev(amt+1,0), cur(amt+1,0);
        for(int j=0;j<=amt;j++) prev[j] = j%coins[0]==0?j/coins[0]:1e9;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                int nottake = prev[j];
                int take=INT_MAX;//since u want min
                if(coins[i]<=j) take = 1+cur[j-coins[i]];
                cur[j] = min(take, nottake);
            }
            prev = cur;
        }
        int ans = prev[amt];
        if(ans>=1e9) return -1;
        else return ans;
    }