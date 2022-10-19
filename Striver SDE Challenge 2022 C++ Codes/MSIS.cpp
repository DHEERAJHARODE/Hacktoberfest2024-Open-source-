int maxSumIS(int nums[], int n)  
	{  
	    vector<int> msis(n);
	    for(int i=0;i<n;i++) msis[i]=nums[i];
	    
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && msis[i] < nums[i]+msis[j])
                    msis[i] = msis[j]+nums[i];
            }
        }
        return *max_element(msis.begin(),msis.end());
	}  