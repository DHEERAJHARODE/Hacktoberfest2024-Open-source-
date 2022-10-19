bool f(int i, int n, int k, vector<int> &arr){
    if(k==0) return true;
    if(i==0) return arr[i]==k;
    bool nottake = f(i-1,n,k,arr);
    bool take=false;
    if(arr[i]<=k){
        take=f(i-1,n,k-arr[i],arr);
    }
    return take or nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n-1,n,k,arr,dp);
}


bool f(int i, int n, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k==0) return true;
    if(i==0) return arr[i]==k;
    if(dp[i][k]!=-1) return dp[i][k];
    bool nottake = f(i-1,n,k,arr,dp);
    bool take=false;
    if(arr[i]<=k)
        take=f(i-1,n,k-arr[i],arr,dp);
    return dp[i][k] = take or nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return f(n-1,n,k,arr,dp);
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1,false));
    for(int i=0;i<n;i++) dp[i][0]=true;
    if(arr[0]<=k) dp[0][arr[0]]=true;//??
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool nottake = dp[i-1][j];
            bool take=false;
            if(arr[i]<=j)
                take=dp[i-1][j-arr[i]];
            dp[i][j] = take || nottake;
        }
    }
    return dp[n-1][k];
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k+1,false), cur(k+1,false);
    prev[arr[0]]=true;//??
    prev[0]=cur[0]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool nottake = prev[j];
            bool take=false;
            if(arr[i]<=j)
                take=prev[j-arr[i]];
            cur[j] = take || nottake;
        }
        prev = cur;
    }
    return prev[k];
}