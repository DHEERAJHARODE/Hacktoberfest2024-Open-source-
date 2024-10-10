# Dutch National Flag Algorithm

The Dutch National Flag Algorithm is a famous algorithm proposed by Edsger Dijkstra. It is used to sort an array of 0s, 1s, and 2s in linear time with constant space complexity. The problem is often described in terms of arranging the elements of a flag with three colors: red, white, and blue.

## Problem Explanation

The idea is to have three sections in the array:

1. The first section (red) contains all 0s.
2. The second section (white) contains all 1s.
3. The third section (blue) contains all 2s.

## Algorithm

We maintain three pointers: `low`, `mid`, and `high`.

- `low` keeps track of the boundary for 0s.
- `mid` traverses the array.
- `high` keeps track of the boundary for 2s.

As we traverse the array:
- If the current element is `0`, we swap it with the element at `low` and increment both `low` and `mid`.
- If the current element is `1`, we just increment `mid`.
- If the current element is `2`, we swap it with the element at `high` and decrement `high`.

## Steps

1. Initialize `low = 0`, `mid = 0`, and `high = arr.length - 1`.
2. Traverse the array using the `mid` pointer.
3. Depending on the value at `arr[mid]`, perform the following actions:
   - If `arr[mid] == 0`: Swap `arr[mid]` with `arr[low]`, then increment both `low` and `mid`.
   - If `arr[mid] == 1`: Just increment `mid`.
   - If `arr[mid] == 2`: Swap `arr[mid]` with `arr[high]`, and decrement `high`.
4. Stop when `mid` exceeds `high`.

## Code Example

```java
public class DutchNationalFlag {

    public static void sortColors(int[] arr) {
        int low = 0, mid = 0;
        int high = arr.length - 1;

        while (mid <= high) {
            switch (arr[mid]) {
                case 0:
                    swap(arr, low, mid);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
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
