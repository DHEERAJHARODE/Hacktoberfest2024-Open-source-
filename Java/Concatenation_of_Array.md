# https://leetcode.com/problems/concatenation-of-array/
1929. Concatenation of Array


class Solution {
    public int[] getConcatenation(int[] nums) {
         int b[] = new int[2*(nums.length)];
        for(int i=0;i<(2*nums.length);i++){
            if(i>=nums.length){
                b[i]=nums[i-nums.length];
            }else {
                b[i] = nums[i];
            }
        }

        
        return b;

    }
}