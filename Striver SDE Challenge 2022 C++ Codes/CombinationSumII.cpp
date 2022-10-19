void cs2(int ind, int sum, int t, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        if(sum==t) {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue; //ind+1 by for loop
            if(sum+nums[i]>t) break;
            temp.push_back(nums[i]); //picked
            cs2(i+1,sum+nums[i],t,temp,nums,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        cs2(0,0,t,temp,nums,ans);
        return ans;
    }