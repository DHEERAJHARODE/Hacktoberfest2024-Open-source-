//https://youtu.be/a5e7RgCdel0
#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[],int n,int exp){
  
    int *count ={new int[10]{}};                //Make an array of size 10 and initialize it with 0

    for(int i=0;i<n;i++){  
        int digit= (arr[i]/exp)%10;              //store the frequency of every digits in count array
        count[digit]++;
    }
    for (int i=1;i<10;i++){                     // Change count array into prefix sum array
        count[i] += count[i - 1];
    }

    int ans[n];
    for (int i=n-1;i>=0;i--){                   //Stable Sorting filling ans array
        int pos= count[(arr[i]/exp)%10]-1;             
        ans[pos] = arr[i];
        count[(arr[i]/exp)%10]--; 
    }

    for (int i=0;i<n;i++){                   //Filling original array with help of ans array
        arr[i]=ans[i];
    } 
}

void radixSort(int arr[],int n){
    int maxi= INT_MIN;              
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);              // Get the maxm element from array
    }
    int exp=1;
    while(exp<=maxi){
        countSort(arr,n,exp);
        exp=exp*10;
    }
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
    radixSort(arr,n);
    print(arr,n);

    return 0;
}