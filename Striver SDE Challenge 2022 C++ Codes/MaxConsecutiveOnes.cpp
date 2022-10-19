int findMaxConsecutiveOnes(vector<int>& nums) {
        int m=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]) m++;
            else{
                ans=max(m,ans);
                m=0;
            }
        }
        ans=max(m,ans);
        return ans;
    }