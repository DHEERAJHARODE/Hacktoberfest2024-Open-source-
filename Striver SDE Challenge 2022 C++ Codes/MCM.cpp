int mcm(int i, int j, int arr[]){
        //step 3: base case
        //base case, a single matrix has no one to multiply, so 0
        if(i==j) return 0;
        
        int minMultips = INT_MAX;
        //step 2: recurrence using for for all possible partitions;
        //j-1 as j is the last index so there is nothing to partition there
        for(int k=i;k<=j-1;k++){
            //add no of multips for current partition
            int multips = arr[i-1] * arr[k] * arr[j]; //derived formula for no of multips b/w 2 mats
            multips += mcm(i, k, arr) + mcm(k+1, j, arr); //partition
            minMultips = min(minMultips, multips);
        }
        return minMultips;
        
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        //PARTITION DP PROBLEM
        
        //step 1: taking entire arr form 0 to n-1
        return mcm(1,N-1,arr);
    }


int mcm(int i, int j, int arr[], vector<vector<int>> &dp){
        //step 3: base case
        //base case, a single matrix has no one to multiply, so 0
        if(i==j) return dp[i][j] = 0;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        int minMultips = INT_MAX;
        //step 2: recurrence using for for all possible partitions;
        //j-1 as j is the last index so there is nothing to partition there
        for(int k=i;k<=j-1;k++){
            //add no of multips for current partition
            int multips = arr[i-1] * arr[k] * arr[j]; //derived formula for no of multips b/w 2 mats
            multips += mcm(i, k, arr,dp) + mcm(k+1, j, arr,dp); //partition
            minMultips = min(minMultips, multips);
        }
        
        return dp[i][j] = minMultips;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        return mcm(1,N-1,arr,dp);
    }


int matrixMultiplication(int N, int arr[])
    {
        //TABULATION IS BOTTOM-UP
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        //base case
        for(int i=0;i<N;i++) dp[i][i] = 0;
        
        for(int i=N-1;i>=1;i--){
            //as i is always left of j
            for(int j=i+1;j<N;j++){
                int minMultips = INT_MAX;
                for(int k=i;k<j;k++){
                    int multips = arr[i-1] * arr[k] * arr[j]; //derived formula for no of multips b/w 2 mats
                    multips += dp[i][k] + dp[k+1][j]; //partition
                    minMultips = min(minMultips, multips);
                }
                dp[i][j] = minMultips;
            }
        }
        //this statement remains same
        return dp[1][N-1];
    }


