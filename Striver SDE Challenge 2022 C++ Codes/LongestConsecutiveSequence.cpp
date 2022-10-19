#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    if(n<=1) return n;
    unordered_set<int> index;
    int maxc=0;
    for(int i=0;i<n;i++){
        index.insert(nums[i]);
    }
    for(int i=0;i<n;i++){
        if(!index.count(nums[i]-1)){//not present in index
            int j=1,c=1;
            while(index.count(nums[i]+j)){
                j++;
                c++;
            }
            if(c>maxc) maxc=c;
        }
    }
    return maxc;
}