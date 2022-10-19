bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k+1,false), cur(k+1,false);
    if(arr[0]<=k) prev[arr[0]]=true;
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
    
    bool canPartition(vector<int>& arr) {
        if(arr.size()==1) return false;
        int k=accumulate(begin(arr),end(arr),0);
        if(k%2!=0) return false;
        k = k / 2;
        return subsetSumToK(arr.size(), k, arr);
    }