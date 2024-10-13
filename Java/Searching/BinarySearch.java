// This class demonstrates the implementation of Binary Search.
public class BinarySearch {

    // Main method to run the program.
    public static void main(String[] args) {
        // Sorted array to search within.
        int[] arr = {-18, -12, -4, 0, 2, 3, 4, 15, 16, 18, 22, 45, 89};

        // Target element to search for.
        int target = 22;

        // Call the binarySearch method and store the result in 'ans'.
        int ans = binarySearch(arr, target);

        // Print the index of the target if found, otherwise -1.
        System.out.println(ans);
    }

    /**
     * This method performs Binary Search on a sorted array.
     * @param arr The array to search in (must be sorted).
     * @param target The value to search for.
     * @return The index of the target element if found; otherwise, -1.
     */
    static int binarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        // Continue searching while there is a valid range to check.
        while (start <= end) {
            // Calculate the middle index in a way that avoids overflow.
            int mid = start + (end - start) / 2;

            // If the target is smaller, search the left half of the array.
            if (target < arr[mid]) {
                end = mid - 1;
            }
            // If the target is larger, search the right half of the array.
            else if (target > arr[mid]) {
                start = mid + 1;
            }
            // If the target is found, return its index.
            else {
                return mid;
            }
        }

        // If the loop exits, the target is not present in the array.
        return -1;
    }
}
