//https://youtu.be/UA_Rmjfj4bw
#include<bits/stdc++.h>
using namespace std;
// Time O(nlogn) and O(n2)      // Space = O(logn) or O(n) 
int partition(int arr[],int low,int high){
    int pivot =arr[low];
    int i =low,j=high;
    while(i<j){
        while(arr[i]<=pivot)i++;
        while(arr[j]>pivot) j--;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int arr[],int low,int high){
    if(low>=high) return;

    int pivotIndex = partition(arr,low,high);
    quickSort(arr,low,pivotIndex-1);
    quickSort(arr,pivotIndex+1,high);

}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={4,6,2,5,7,9,1,3};
    int n= sizeof(arr)/sizeof(int);
    print(arr,n);
    quickSort(arr,0,n-1);
    print(arr,n);

    return 0;
}