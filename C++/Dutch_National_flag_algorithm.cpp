#include <bits/stdc++.h>
using namespace std;

/* Dutch National flag algorithm (3 Pointer Approach)

In this algorithm we will be using 3 pointers named low, mid, and high. We will be using these 3 pointers to move around the values. The primary goal here is to move 0s to the left and 2s to the right of the array and at the same time all the 1s shall be in the middle region of the array and hence the array will be sorted.

Time Complexity : O(N)
Space Complexity : O(1)

*/
void sortColors(vector<int> &nums)
{
    int lo = 0;
    int hi = nums.size() - 1;
    int mid = 0;

    while (mid <= hi)
    {
        switch (nums[mid])
        {

        // If the element is 0
        case 0:
            swap(nums[lo++], nums[mid++]);
            break;

        // If the element is 1 .
        case 1:
            mid++;
            break;

        // If the element is 2
        case 2:
            swap(nums[mid], nums[hi--]);
            break;
        }
    }
}

int main(){
    vector<int>  nums={1,0,2,1,0,1,0,0,2,1,2,2};
    sortColors(nums);
    for(auto n : nums)cout<<n<<", ";
}