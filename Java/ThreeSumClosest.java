class ThreeSumClosest {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int diff = Integer.MAX_VALUE;
        for(int i=0;i<nums.length;i++){
            int l = i+1;
            int r = nums.length - 1;
            int k = target - nums[i];
            while(l < r){
                if(nums[l] + nums[r] == k){
                    return target;
                }else if(nums[l] + nums[r] > k){
                    if(Math.abs(diff-target)>Math.abs(nums[i] + nums[l] + nums[r] - target))
                    diff = nums[i] + nums[l] + nums[r];
                    r--;
                }else{
                    if(Math.abs(diff-target)>Math.abs(nums[i] + nums[l] + nums[r] - target))
                    diff =  nums[i] + nums[l] + nums[r];
                    l++;
                }
            }
           
        }
        return diff;
    }
}