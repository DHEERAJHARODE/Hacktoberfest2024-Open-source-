#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void sortColors(vector<int> &nums){
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high){
        if (nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{
    vector<int> arr = {2,0,2,1,1,0};
    sortColors(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}