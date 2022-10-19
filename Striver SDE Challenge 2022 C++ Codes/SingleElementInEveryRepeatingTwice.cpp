class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(),beg=0,end=n-1,mid;
        //boundary conds
        if(n==1)
            return nums[0];
        else if(nums[0]!=nums[1])
            return nums[0];
        else if(nums[end]!=nums[end-1])
            return nums[end];
        while(beg<=end){
            mid = beg+(end-beg)/2;
            //odd even check for pair
            if((nums[mid]==nums[mid-1] && mid%2!=0) || (nums[mid]==nums[mid+1] && mid%2==0)) //pair order not disrupted
                beg = mid+1;
            else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            else //pair order disrupted
                end = mid-1;
        }
        return -1;
    }
};