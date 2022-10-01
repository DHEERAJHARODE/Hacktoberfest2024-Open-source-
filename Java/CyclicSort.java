// This is the Basic Syntax to sort the given array using Cyclic Sort Method

public class Cyclicsort {
    public static void main(String[] args) {
        int[] arr = {4,5,3,2,1};
        Cyclicsort(arr);
        System.out.println(Arrays.toString(arr));

    }
    static int[] Cyclicsort(int[] nums){
        int i = 0;
        while(i < nums.length){
            if(nums[i]== i+1){
                i++;
            }else{
                int temp = nums[nums[i]-1];
               nums[nums[i]-1] = nums[i];
               nums[i]= temp;
            }
        }
        return nums;
    }
}
