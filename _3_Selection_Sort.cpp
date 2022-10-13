//https://youtu.be/B-nqY6IYqVw
#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        if(i!=min){
            swap(arr[i],arr[min]);
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
    int arr[]={4,1,9,2,3};
    int n= sizeof(arr)/sizeof(int);
    print(arr,n);
    selectionSort(arr,n);
    print(arr,n);

    return 0;
}