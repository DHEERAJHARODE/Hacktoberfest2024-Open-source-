#include <bits/stdc++.h>
using namespace std;

int res = 0;
void mergesort(vector<int> &nums, int l, int mid, int h){
    int i = l;
    int j = mid + 1;
    while (i <= mid && j <= h){
        long long temp = nums[j];
        if (nums[i] > 2 * temp){
            res += mid - i + 1;
            j++;
        }
        else
            i++;
    }
    sort(nums.begin() + l, nums.begin() + h + 1);
}

void merge(vector<int> &nums, int l, int h){
    if (l >= h)
        return;
    int mid = (l + h) / 2;
    merge(nums, l, mid);
    merge(nums, mid + 1, h);
    mergesort(nums, l, mid, h);
}
int reversePairs(vector<int> &nums){
    if (nums.size() == 1) return 0;

    merge(nums, 0, nums.size() - 1);

    return res;
}

int main(){
    vector<int> nums = {1,3,2,3,1};
    cout << reversePairs(nums) << endl;
    return 0;
}