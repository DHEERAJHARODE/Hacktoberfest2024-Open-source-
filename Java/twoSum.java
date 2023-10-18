class Solution {
    public int[] twoSum(int[] nums, int target) {
        int arr1[] = new int[2];
        for (int i=0;i<=nums.length-2;i++){
            for(int j=i+1;j<=nums.length-1;j++){
                if (target == nums[i]+nums[j])
                {
                    arr1[0]=i;
                    arr1[1]=j;
                }
        }
        }
        return arr1;
    }
}
