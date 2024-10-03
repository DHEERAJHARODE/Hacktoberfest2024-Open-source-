#include <stdio.h>

int linearSearchRecursive(int arr[], int size, int target, int index, int *counter) {
    if (index >= size) {
        return -1; 
    }
    
    (*counter)++; 
    
    if (arr[index] == target) {
        return index; 
    }
    
    return linearSearchRecursive(arr, size, target, index + 1, counter); 
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int target;
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int counter = 0; 
    int result = linearSearchRecursive(array, size, target, 0, &counter);

    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found in the array\n", target);
    }

    printf("Total comparisons made: %d\n", counter);

    return 0;
}
