#include <stdio.h>

int main() {
    // Write C code here
    int binary_search( int arr[],int low, int high,int element);
    int a[]={1,2,3,4,5,6,7,8,9,10};
    
    int size=sizeof a/sizeof (a[0]);
    int b;
    printf("enter element to search in array;");
    scanf("%d",&b);
    int result=binary_search(a,0, size-1,b);
    printf("%d found at %d index",b,result);
    return 0;
}
int binary_search(int arr[],int low, int high,int element){
    
    int mid=low + ((high - low) / 2);
    if(arr[mid]==element){
       return mid;
    }
    if(arr[mid]>element){
        return binary_search(arr, low,  mid-1, element);
    }
    if(arr[mid]<element){
        return binary_search(arr, mid+1,  high, element);
    }
    else{
        return -1;
    }
}
