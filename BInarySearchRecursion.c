#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int target, int *counter) {
    (*counter)++;

    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, right, target, counter); 
        } else {
            return binarySearchRecursive(arr, left, mid - 1, target, counter); 
        }
    }

    return -1; 
}

int main() {
    int size;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter %d elements in sorted order for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int target;
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int counter = 0; 
    int result = binarySearchRecursive(array, 0, size - 1, target, &counter);

    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found in the array\n", target);
    }

    printf("Total comparisons made: %d\n", counter);

    return 0;
}
