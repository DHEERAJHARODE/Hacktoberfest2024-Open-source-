#include<bits/stdc++.h>
int binarySearch(int arr[],int size,int target){
   int low=0;
  int high=size-1;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(arr[mid]==target){
      return mid;
      }
    else if(arr[mid]>target){
      high=mid-1;
      }
    else{
      low=mid+1;
      }
    }
  return -1;
  }
int main(){
   int size;
   cin>>size;
   int arr[size];
  for(int i=0;i<size;i++){
    cin>>arr[i];
    }
  int target;
  cin>>target;
  sort(arr,arr+n);
  int ans = binarySearch(arr,size,target);
  cout<<"Element found at index "<<ans<<endl;
   return 0;
  }
