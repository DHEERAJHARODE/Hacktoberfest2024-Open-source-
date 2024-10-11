//the-number-of-the-smallest-unoccupied-chair

/*There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.*/



class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        //giving tle
        // int maxi = INT_MIN;
        // for(int i = 0;i<nums.size()-1;i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         if(nums[i] <= nums[j]){
        //             maxi = max(maxi,j-i);
        //         }
        //     }
        // }
        // return maxi == INT_MIN?0:maxi;

        stack<int>st;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(st.empty() || nums[st.top()] > nums[i]){
                st.push(i);
            }
        }
        int maxi = INT_MIN;
        for(int j = n-1;j>=0;j--){
            while(!st.empty() && nums[st.top()] <= nums[j]){
                maxi = max(maxi,j-st.top());
                st.pop();
            }
        }
        return maxi;
    }
};
