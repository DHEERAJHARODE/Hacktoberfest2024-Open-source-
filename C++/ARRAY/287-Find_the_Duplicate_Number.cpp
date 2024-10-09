#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int findDuplicate(vector<int> &nums){
    unordered_map<int, int> mp;
    for (int num : nums){
        mp[num]++;
    }
    for (auto x : mp){
        if (x.second > 1){
            return x.first;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,3,4,2,2};
    int duplicate = findDuplicate(arr);
    cout << duplicate << endl;
    return 0;
}