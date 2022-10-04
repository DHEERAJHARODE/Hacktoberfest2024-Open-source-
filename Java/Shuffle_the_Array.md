# https://leetcode.com/problems/shuffle-the-array/
1470. Shuffle the Array 


class Solution {
    public int[] shuffle(int[] nums, int n) {
        int b[] = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            b[i] =nums[i];
        }
        for(int i=0;i<2*n;i+=2){
            nums[i]= b[i/2];
            nums[i+1]=b[n+i/2];
        }
        return nums;
    }