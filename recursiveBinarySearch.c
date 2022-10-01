#include<stdio.h>
#include<stdlib.h>
int recursiveBinarySearch(int *array, int start_index, int end_index, int element){
   if (end_index >= start_index){
      int mid = start_index + (end_index - start_index )/2;
      if (array[mid] == element)
         return mid;
      if (array[mid] > element)
         return recursiveBinarySearch(array, start_index, mid-1, element);
      return recursiveBinarySearch(array, mid+1, end_index, element);
   }
   return -1;
}
int main(void){
    int n,element;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int *arr = (int*)calloc(n, sizeof(int));
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&element);
    int at_index = recursiveBinarySearch(arr, 0, n-1, element);
    if(at_index == -1 ) {
        printf("Element not found in the array ");
    }
    else {
        printf("Element found at index : %d",at_index);
    }
    return 0;
}
