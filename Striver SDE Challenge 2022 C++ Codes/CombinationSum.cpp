void cs(int ind, int sum, int t, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        if(ind==nums.size()){
            if(sum==t) ans.push_back(temp);
            return;
        }
        if(sum+nums[ind]<=t){
            temp.push_back(nums[ind]); //picked
            cs(ind,sum+nums[ind],t,temp,nums,ans);
            temp.pop_back();
        }
        cs(ind+1,sum,t,temp,nums,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        vector<int> temp;
        vector<vector<int>> ans;
        cs(0,0,t,temp,nums,ans);
        return ans;
    }