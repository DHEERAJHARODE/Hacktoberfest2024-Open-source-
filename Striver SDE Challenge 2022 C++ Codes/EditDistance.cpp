//DP 2D
int f(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        //replace same char
        // int a = 1+f(s1,s2,i-1,j-1);
        //delete
        // int b = 1+f(s1,s2,i-1,j);
        //insert same char
        // int c = 1+f(s1,s2,i,j-1);
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = f(s1,s2,i-1,j-1,dp);
        return dp[i][j] = 1 + min(f(s1,s2,i-1,j-1,dp),min(f(s1,s2,i-1,j,dp),f(s1,s2,i,j-1,dp)));
    }
    
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(s1,s2,n-1,m-1,dp);
    }

//TABULATION 2d
int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        //base cases
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //possible cases
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 
                    1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n][m];
    }

//TABULATION 1D
int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n==0 && m==0) return 0;
        else if(n==0) return m;
        else if(m==0) return n;
        // else all this
        //m+1 as we need only 1 prev row whihc has size m+1
        vector<int> prev(m+1, 0), cur(m+1, 0);
        //base case 1
        for(int j=0;j<=m;j++) prev[j]=j;
        
        for(int i=1;i<=n;i++){
		//base case 2
            cur[0]=i;
            for(int j=1;j<=m;j++){
                //possible cases
                if(s1[i-1] == s2[j-1]) cur[j] = prev[j-1];
                else cur[j] = 
                    1 + min(prev[j-1],min(prev[j],cur[j-1]));
            }
            prev = cur;
        }
        return cur[m];
    }