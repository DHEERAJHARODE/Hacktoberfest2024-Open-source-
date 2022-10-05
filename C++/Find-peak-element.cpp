#include <iostream>

using namespace std;
int binarySearch(int arr[],int low,int high)
{
     
     while(low<=high){
     int mid=(low+high)/2;
    //  Here we are checking the condition if the element is peak element or not
     if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
         return mid;
     }
     
     else if(arr[mid]<arr[mid+1]){
         return binarySearch(arr,mid+1,high);
     }
     else{
         return binarySearch(arr,0,mid-1);
     }
     }
     return -1;
 
}
 
int search(int arr[],int n){
 if(n==1)
  return arr[0];
 
 if(arr[0]>arr[1]){
     return arr[0];
 }
 if(arr[n-1]>arr[n-2]){
     return arr[n-1];
 }
 
return binarySearch(arr,0,n-1);
    
}

int main()
{
    int arra[]={1,2,3,4,3,2};
    cout<<search(arra,6);
}
