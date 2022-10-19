#include <bits/stdc++.h> 
int counter(vector<int>& nums, int b, int m, int e){
        int i=b,j=m+1,count=0;
        while(i<=m && j<=e){
            if(nums[i]>(long long)2*nums[j]){
                count += m-i+1;//since left subarry is sorted, all elems to the right of it till mid would follow same condition
                j++;
            }
            else i++;
        }
        sort(nums.begin() + b, nums.begin() + e + 1);//merge sort stl
        return count;
    }
int merge_sort(vector<int>& nums, int b, int e){
    int count =0;
    if(b<e){
        int m=b+(e-b)/2;
        count += merge_sort(nums,b,m);
        count += merge_sort(nums,m+1,e);
        count += counter(nums,b,m,e);
    }
    return count;
}
int reversePairs(vector<int>& nums, int n) {
    return merge_sort(nums,0,nums.size()-1);
}