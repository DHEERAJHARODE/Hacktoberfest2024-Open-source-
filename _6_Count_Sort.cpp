//https://youtu.be/p-OyKUgIrx4
#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[],int n){
    int maxi= INT_MIN;              
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);              // Get the maxm element from array
    }

    int *count ={new int[maxi+1]{}};        //Make an array of size maxm element of array and initialize it with 0

    for(int i=0;i<n;i++){                   //store the frequency of every elements in count array
        count[arr[i]]++;
    }
    for (int i=1;i<maxi+1;i++){              // Change count array into prefix sum array
        count[i] += count[i - 1];
    }

    int ans[n];
    for (int i=n-1;i>=0;i--){              //Stable Sorting filling ans array
        ans[count[arr[i]]-1] = arr[i];

        count[arr[i]]--; 
    }
    
    for (int i=0;i<n;i++){              //Filling original array with help of ans array
        arr[i]=ans[i];
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
    countSort(arr,n);
    print(arr,n);

    return 0;
}