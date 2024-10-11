//maximum-width-ramp
/*962. Maximum Width Ramp
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.*/

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
