#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxIndex = 0;
    for(int i=0;i<nums.size();i++){
        if(i>maxIndex) return false;
        maxIndex = max(maxIndex,i+nums[i]);
    }
    return true;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    cout<<canJump(nums)<<endl; 
    return 0;
}