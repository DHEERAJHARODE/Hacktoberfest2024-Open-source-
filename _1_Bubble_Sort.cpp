// https://youtu.be/bBQkErahU9c
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={4,3,7,1,5};
    int n= sizeof(arr)/sizeof(int);
    print(arr,n);
    bubbleSort(arr,n);
    print(arr,n); 
    return 0;
}