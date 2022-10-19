class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<=3) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int left, right;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                left=j+1,right=nums.size()-1;
                while(left<right){
                    if(long(nums[i])+long(nums[j])+long(nums[left])+long(nums[right])==long(target)) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        while(left<right && nums[left]==temp[2]) left++;
                        while(left<right && nums[right]==temp[3]) right--;
                    }
                    else if(long(nums[i])+long(nums[j])+long(nums[left])+long(nums[right])<long(target))
                        left++;
                    else right--;
                    }//while
                while(j+1<nums.size() && nums[j+1]==nums[j]) j++;
            }//j
            while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
        }//i
        return ans;
    }
};