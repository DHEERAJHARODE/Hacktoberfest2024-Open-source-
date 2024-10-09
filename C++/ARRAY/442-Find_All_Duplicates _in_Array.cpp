#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums){
    unordered_map<int, int> mp;
    for (int num : nums){
        mp[num]++;
    }
    vector<int> ans;
    for (auto x : mp){
        if (x.second > 1)
        {
            ans.push_back(x.first);
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = findDuplicates(nums);
    cout << "Duplicate numbers: ";
    for (int num : duplicates){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}