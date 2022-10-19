int maxProduct(vector<int>& nums) {
        int cmax=1,cmin=1,maxp=nums[0];
        for(int i=0;i<nums.size();i++){
            int tmp = nums[i]*cmax;
            cmax = max( max(tmp, nums[i]*cmin), nums[i] );
            cmin = min( min(tmp, nums[i]*cmin), nums[i] );
            maxp = max(maxp,cmax);
        }
        return maxp;
    }