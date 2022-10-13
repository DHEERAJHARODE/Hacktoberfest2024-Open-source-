//https://youtu.be/aDX3MFL0tYs
#include<bits/stdc++.h>
using namespace std;
// Time O(nlogn)             // Space = O(n) 
void merge(int arr[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int merged[high+1];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            merged[k++]=arr[i++];
        }
        else{
            merged[k++]=arr[j++];
        }
    }
    while(i<=mid){
        merged[k++]=arr[i++];
    }
    while(j<=high){
        merged[k++]=arr[j++];
    }

    for (i = low; i < k; i++)  {
    arr[i] = merged[i];
    }
}

void mergeSort(int arr[],int low,int high){
    if(low>=high) return;

    int mid = low + (high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={23,4,6,14,7,11,34,9};
    int n= sizeof(arr)/sizeof(int);
    print(arr,n);
    mergeSort(arr,0,n-1);
    print(arr,n);

    return 0;
}