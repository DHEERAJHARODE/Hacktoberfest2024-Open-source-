#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k){
    unordered_map<int, int> map;
    map[0] = 1;
    int prefix_sum = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++){
        prefix_sum += nums[i];
        int remainder = prefix_sum % k;
        if (remainder < 0){
            remainder += k;
        }
        if (map.find(remainder) != map.end()){
            count += map[remainder];
            map[remainder]++;
        }
        else{
            map[remainder] = 1;
        }
    }
    return count;
}
int main(){
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int result = subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << ": " << result << endl;
    return 0;
}