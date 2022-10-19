class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        deque<int> dq; //we'd input indexes in it
        for(int i=0;i<n;i++){
            if(!dq.empty() and dq.front()==i-k) dq.pop_front();
            while(!dq.empty() and nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};