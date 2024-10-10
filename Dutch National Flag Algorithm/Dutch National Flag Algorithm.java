public class DutchNationalFlag {

    
    public static void sortColors(int[] arr) {
        int low = 0, mid = 0;
        int high = arr.length - 1;

        // Traverse the array
        while (mid <= high) {
            switch (arr[mid]) {
                // If the element is 0
                case 0:
                    swap(arr, low, mid);
                    low++;
                    mid++;
                    break;
                // If the element is 1
                case 1:
                    mid++;
                    break;
                // If the element is 2
                case 2:
                    swap(arr, mid, high);
                    high--;
                    break;
            }
        }
    }

  
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    
    public static void main(String[] args) {
        int[] arr = {2, 0, 2, 1, 1, 0};

        System.out.println("Before sorting:");
        for (int num : arr) {
            System.out.print(num + " ");
        }

        sortColors(arr);

        System.out.println("\nAfter sorting:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
