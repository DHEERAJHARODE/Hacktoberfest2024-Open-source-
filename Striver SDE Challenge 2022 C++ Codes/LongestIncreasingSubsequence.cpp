//RECURSION
int lis(int ind, int prev, vector<int> &nums){
        if(ind==nums.size()) return 0;
        //not take
        int len = 0 + lis(ind+1,prev,nums);
        
        //take
        if(prev == -1 || nums[ind] > nums[prev])
            len = max(len, 1 + lis(ind+1,ind,nums));
        //max so as the check recursively if current len is max or the one we get from                 another subarr
        return len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return lis(0,-1,nums);
    }

//MEMOISATION DP with O(NXN) S(NXN) => BAD
int lis(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(ind==nums.size()) return 0;
        int len;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        else{
            //not take
            len = 0 + lis(ind+1,prev,nums,dp);
            //take
            if(prev == -1 || nums[ind] > nums[prev])
                len = max(len, 1 + lis(ind+1,ind,nums,dp));
            //max so as the check recursively if current len is max or the one we get from                 another subarr
        }
        return dp[ind][prev+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
        //n+1 since v r using prev (& ind) to build our dp arr but prev=[-1,n-1] so v +1 to           prev to bring it in [0,n]=n+1 elements
        return lis(0,-1,nums,dp);
    }

//TABULATION DP with O(NXN) S(NXN)
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        // //n+1 since v r using prev (& ind) to build our dp arr but prev=[-1,n-1] so v +1 to           prev to bring it in [0,n]=n+1 elements
        // return lis(0,-1,nums,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=-1;j--){
                int len=dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j])
                    len = max(len, 1 + dp[i+1][i+1]);
                dp[i][j+1]=len;
            }
        }
        return dp[0][0];//since filling from bottom up
    }


//TABULATION DP with O(NXN) S(N)
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //n+1 since v r using prev (& ind) to build our dp arr but prev=[-1,n-1] so v +1 to           prev to bring it in [0,n]=n+1 elements
        vector<int> next(n+1,0),cur(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=-1;j--){
                int len=next[j+1];
                if(j==-1 || nums[i]>nums[j])
                    len = max(len, 1 + next[i+1]);
                cur[j+1]=len;
            }
            next = cur;
        }
        return cur[0];//or next[0] since both same
    }


//LOWER BOUND (BS) 0(NlongN) S(N)
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>lis.back()) lis.push_back(nums[i]);
            else{
                int lb = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                lis[lb]=nums[i];
            }
        }
        return lis.size();
    }
