#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++){
        int secondElement = target - nums[i];
        if (mp.find(secondElement) != mp.end()){
            return {mp[secondElement], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}