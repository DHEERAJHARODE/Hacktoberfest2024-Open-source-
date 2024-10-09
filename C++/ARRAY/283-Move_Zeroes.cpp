#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums){
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++){
        if (nums[i] != 0){
            int temp = nums[i];
            nums[i] = nums[count];
            nums[count] = temp;
            count++;
        }
    }
}

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int num : nums){
        cout << num << " ";
    }
    return 0;
}