// This class contains the implementation of Linear Search.
public class LinearSearch {

    // The main method is the entry point of the Java application.
    public static void main(String[] args) {

        // An array of integers to search within.
        int[] nums = {23, 45, 1, 2, 8, 19, -3, 16, -11, 28};

        // The target element to search for in the array.
        int target = 19;

        // Calling the linearSearch method and storing the result in 'ans'.
        boolean ans = linearSearch(nums, target);

        // Printing whether the target was found or not.
        System.out.println("Target found: " + ans);
    }

    /**
     * This method performs linear search on the given array.
     * @param arr The array to search in.
     * @param target The element to search for.
     * @return true if the target is found, otherwise false.
     */
    static boolean linearSearch(int[] arr, int target) {

        // Loop through each element in the array.
        for (int element : arr) {

            // If the current element matches the target, return true.
            if (element == target) {
                return true;
            }
        }

        // If the target is not found after checking all elements, return false.
        return false;
    }
}
