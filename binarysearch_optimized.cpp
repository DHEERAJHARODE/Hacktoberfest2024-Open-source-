#include <iostream>
using namespace std;
int binarySearch(int arr[],int key, int size){
  int s = 0;
  int e = size-1;
  while(s<e){
    int mid = e + (s-e)/2;
    if (arr[mid]==key){
      return key;
    }
    else if(arr[mid]>key){
      s = mid+1;
    }
    else{
      e = mid;
    }
  }
  return -1;
}
int main(){
  // test binary seach by importing any array and using it's function
}
