//no on CS
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me=nums[0],c=1;
        for(int i=1;i<size(nums);i++){
            if(nums[i]==me) c++;
            else c--;
            if(c==0) me=nums[i+1];
        }
        return me;
    }
};