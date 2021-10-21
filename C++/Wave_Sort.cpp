#include<iostream>
using namespace std;

void WaveSort(int arr[], int n){
    for(int i=1; i<n; i+=2){

        if(arr[i] > arr[i-1])
            swap(arr[i], arr[i-1]);
        
        if((arr[i] > arr[i+1]) && (i <= n-2))
            swap(arr[i], arr[i+1]);
    }
}

int main(){
    int n;
    cout<<"Enter N: ";
    cin>>n;

    int arr[n]; 
    cout<<"Enter Elements of Array: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    WaveSort(arr, n);

    cout<<"Sorted Array :: \n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
