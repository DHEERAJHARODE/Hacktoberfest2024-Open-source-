#include <iostream>
using namespace std;

void merge(int arr[], int s, int e) {
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    // create two sub arrays from main array separating at mid
    int *left = new int[len1];
    int *right = new int[len2];

    // Copy values in left subarray
    int arrayIndex = s;
    for(int i=0; i<len1; i++) {
        left[i] = arr[arrayIndex++];
    }
    // Copy values in right subarray
    arrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        right[i] = arr[arrayIndex++];
    }

    // Merge left and right subarrays
    arrayIndex = s;
    int index1 = 0, index2 = 0;

    while(index1 < len1 && index2 < len2) {
        if(left[index1] < right[index2]) {
            arr[arrayIndex++] = left[index1++];
        } else {
            arr[arrayIndex++] = right[index2++];
        }
    }

    while(index1 < len1)
        arr[arrayIndex++] = left[index1++];

    while(index2 < len2) 
        arr[arrayIndex++] = right[index2++];
    
    delete [] left;
    delete [] right;
}