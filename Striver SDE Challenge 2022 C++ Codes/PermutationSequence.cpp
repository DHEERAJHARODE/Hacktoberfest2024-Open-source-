string getPermutation(int n, int k) {
        k=k-1;//o-based index
        int f=1;
        vector<int> nums;
        //factorial of n-1
        for(int i=1;i<=n-1;i++){
            f=f*i;
            nums.push_back(i);
        }
        nums.push_back(n); 
        string ans="";
        while(true){
            ans=ans+to_string(nums[k/f]);
            nums.erase(nums.begin()+k/f);
            if(!nums.size()) break;
            k=k%f;
            f=f/nums.size();
        }
        return ans;
    }