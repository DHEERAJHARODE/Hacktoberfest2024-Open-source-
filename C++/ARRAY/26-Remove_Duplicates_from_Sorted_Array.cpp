#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int> &nums){
    int n = nums.size();
    int idx = 1;
    for (int i = 1; i < n; i++){
        if (nums[idx - 1] != nums[i]){
            nums[idx] = nums[i];
            idx++;
        }
    }
    return idx;
}
int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(nums);
    return 0;
}