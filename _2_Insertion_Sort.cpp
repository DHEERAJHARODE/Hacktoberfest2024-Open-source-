//https://youtu.be/wWhAhp6PIuQ
#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n){

    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={8,4,1,5,9,2};
    int n= sizeof(arr)/sizeof(int);
    print(arr,n);
    insertionSort(arr,n);
    print(arr,n); 
    return 0;
}