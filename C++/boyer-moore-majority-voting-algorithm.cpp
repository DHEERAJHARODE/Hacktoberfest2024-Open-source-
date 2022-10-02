#include<bits/stdc++.h>
using namespace std;

/* boyer-moore-majority-voting-algorithm 
This algorithm is used to find Majority Element that occurs more than N/2 times in the Given Input array.

Time complexity : O(N)
Space complexity : O(1)

The question clearly states that the nums array has a majority element. Since it has a majority element we can say definitely the count is more than N/2.

Majority element count = N/2 + x;

Minority/Other elements = N/2 – x;

Where x is the number of times it occurs after reaching the minimum value N/2.

Now, we can say that count of minority elements and majority elements are equal up to a certain point of time in the array. So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element. 

*/


int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num==candidate) count += 1; 
            else count -= 1; 
        }

        return candidate;
    }

int main(){

    vector<int> nums={2,2,3,2,4,5,3,2,2};
    cout<<majorityElement(nums);
}