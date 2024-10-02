import java.util.Scanner;

class ThreeWayMergeSort {
    public static void sortThreeWay(Integer[] arr) {
        if (arr == null) return;
        Integer[] tempArray = new Integer[arr.length];
        for (int i = 0; i < tempArray.length; i++) tempArray[i] = arr[i];
        sortRecursive(tempArray, 0, arr.length, arr);
        for (int i = 0; i < tempArray.length; i++) arr[i] = tempArray[i];
    }

    public static void sortRecursive(Integer[] arr, int low, int high, Integer[] tempArray) {
        if (high - low < 2) return;
        int mid1 = low + ((high - low) / 3);
        int mid2 = low + 2 * ((high - low) / 3) + 1;
        sortRecursive(tempArray, low, mid1, arr);
        sortRecursive(tempArray, mid1, mid2, arr);
        sortRecursive(tempArray, mid2, high, arr);
        mergeArrays(tempArray, low, mid1, mid2, high, arr);
    }

    public static void mergeArrays(Integer[] arr, int low, int mid1, int mid2, int high, Integer[] tempArray) {
        int i = low, j = mid1, k = mid2, l = low;
        while ((i < mid1) && (j < mid2) && (k < high)) {
            if (arr[i].compareTo(arr[j]) < 0) {
                if (arr[i].compareTo(arr[k]) < 0) tempArray[l++] = arr[i++];
                else tempArray[l++] = arr[k++];
            } else {
                if (arr[j].compareTo(arr[k]) < 0) tempArray[l++] = arr[j++];
                else tempArray[l++] = arr[k++];
            }
        }
        while ((i < mid1) && (j < mid2)) {
            if (arr[i].compareTo(arr[j]) < 0) tempArray[l++] = arr[i++];
            else tempArray[l++] = arr[j++];
        }
        while ((j < mid2) && (k < high)) {
            if (arr[j].compareTo(arr[k]) < 0) tempArray[l++] = arr[j++];
            else tempArray[l++] = arr[k++];
        }
        while ((i < mid1) && (k < high)) {
            if (arr[i].compareTo(arr[k]) < 0) tempArray[l++] = arr[i++];
            else tempArray[l++] = arr[k++];
        }
        while (i < mid1) tempArray[l++] = arr[i++];
        while (j < mid2) tempArray[l++] = arr[j++];
        while (k < high) tempArray[l++] = arr[k++];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        Integer[] arr = new Integer[n];
        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        sortThreeWay(arr);
        System.out.println("Sorted array:");
        for (int i = 0; i < arr.length; i++) System.out.print(arr[i] + " ");
    }
}
