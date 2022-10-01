public class SortAndSearch {
    public static void main(String[] args) {
        int[] arr = {19, 21, 10, 11, 13, 17, 37, 53, 73, 94};
        bubbleSort(arr);
        System.out.print(binary(arr, 11));
    }
    
    static void bubbleSort(int[] arr) {
        boolean swapped;
        for(int i = 0; i < arr.length; i++) {
            swapped = false;
            for(int j = 1; j < arr.length - i; j++) {
                if(arr[j] < arr[j - 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
            }
            if(!swapped) {
                break;
            }
        }
    }
    
    static int binary(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(target < arr[mid]) {
                end = mid - 1;
            } else if(target > arr[mid]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}