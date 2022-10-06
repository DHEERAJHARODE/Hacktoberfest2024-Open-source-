// TimSort in C language

#include<stdio.h>

const int RUN=32;
int i;

// Function to sort array from left to right index of size atmost RUN
void insertionSort(int a[], int left, int right)
{
    for (i=left+1; i<=right; i++)
    {
        int temp=arr[i];
        int j=i-1;
        while (j>=left && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
 
// Function to merge the sorted runs
void merge(int a[], int leftVal, int middleVal, int rightVal)
{
    int len1=middleVal-leftVal+1, len2=rightVal-middleVal;
    // The main array is broken into two arrays
    int left[len1], right[len2];

    for (i=0; i<len1; i++)
        left[i]=arr[leftVal+i];

    for (i=0; i<len2; i++)
        right[i]=arr[middleVal+1+i];
 
    int j=0, x=leftVal;
    i=0;
 
    // Two arrays are merged into a larger sub array after comparing
    while (i<len1 && j<len2)
    {
        if (left[i]<=right[j])
        {
            arr[x]=left[i];
            i++;
        }

        else
        {
            arr[x]=right[j];
            j++;
        }

        x++;
    }

    while (i<len1)
    {
        arr[x]=left[i];
        x++;
        i++;
    }

    while (j<len2)
    {
        arr[x]=right[j];
        x++;
        j++;
    }
}
 
// Function for Timsort
void timSort(int a[], int n)
{
     
    // Sort individual subarrays of size RUN
    for (i=0; i<n; i+=RUN)
        insertionSort(arr, i, min((i+RUN-1), (n-1)));
 
    // Merging started
    for (int size=RUN; size<n; size=2*size)
    {
        for (int left=0; left<n; left+=2*size)
        {
            int mid=left+size-1;
            int right=min((left+2*size-1), (n-1));
 
            // Merging right and left sub arrays
              if(mid<right)
                merge(a, left, mid, right);
        }
    }
}
 
// Function to print array
void printArray(int a[], int n)
{
    for (i=0; i<n; i++)
        printf("%d  ", arr[i]);
}

// The main function
int main()
{
    int array[] = {99, 23, 0, -94, -64, -41, 89, 0, -33, 32, 27, 3, 88, 97, 7};
    int sizeOfArray = sizeof(arr)/sizeof(arr[0]);

    printf("The given array is :");
    printArray(array, sizeOfArray);

    timSort(array, sizeOfArray);
 
    printf("The sorted array is :");
    printArray(array, sizeOfArray);

    return 0;
}