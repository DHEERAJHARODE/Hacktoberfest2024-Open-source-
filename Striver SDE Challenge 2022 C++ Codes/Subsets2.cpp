#include<bits/stdc++.h>
void s2(int ind, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
    ans.push_back(temp);//adding to ans the current ss
    for(int i=ind;i<n;i++){//choosing and not choosing each uniqe elem in nums
        if(i!=ind && nums[i]==nums[i-1]) continue; //skipping dups
        //i!=ind as when i==ind, we are in fact choosing that ind val so we cant ofc skip it, can we?
        temp.push_back(nums[i]);
        s2(i+1,n,nums,temp,ans);
        temp.pop_back(); //we dont want this ind val in next subarr
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end()); //to avoid dups
        s2(0,n,nums,temp,ans);
        return ans;
}