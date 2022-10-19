void pt(int ind, vector<vector<int>>& ans, vector<int>& nums){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            pt(ind+1,ans,nums);
            swap(nums[ind],nums[i]); // reswap to pass unchanged arr to next recn call
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        pt(0,ans,nums);
        return ans;
    }