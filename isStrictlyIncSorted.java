public class isStrictlyIncSorted {
    public static boolean isIncreasing(int[] arr, int index) {
        if (index == arr.length-1) {
            return true;
        }

        if (!isIncreasing(arr, index+1)){
            return false;
        }

        return arr[index] < arr[index+1];
    }
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,6};

        System.out.println(isIncreasing(arr,0));
    }
}
