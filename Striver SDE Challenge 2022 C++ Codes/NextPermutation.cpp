void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
        
        //find ind where nums[i]>nums[i-1]
    	for (k = n - 2; k >= 0; k--)
            if (nums[k] < nums[k + 1])
                break;
        
        //no such index exists, array in desc order
    	if (k < 0)
    	    reverse(nums.begin(), nums.end());
        else {
            //find nums[l] just greater than nums[k]
    	    for (l = n - 1; l > k; l--)
                if (nums[l] > nums[k])
                    break;
            
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }