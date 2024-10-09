#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums){
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int num : nums){
        mp[num]++;
    }

    for (auto x : mp){
        if ((n / 2) < x.second){
            return x.first;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums);
    return 0;
}