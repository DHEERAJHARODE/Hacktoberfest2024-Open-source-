#include<bits/stdc++.h>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int sum=0,result=0;
    mp[sum]=1;
    for(int n : nums){
        sum+=n;
        result+=mp[sum-k];
        mp[sum]++;
    }
    return result;
}


int main(){
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << "Number of subarrays with sum " << k << ": " << subarraySum(nums, k) << endl;
    return 0;
}