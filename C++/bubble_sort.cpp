//Cpp code for bubble sort
#include<iostream>
using namespace std;

void bubblesortmod(int arr[],int n){
    for(int i=1;i<n;i++){
        bool swapped=false;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    bubblesortmod(arr,n);

    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}

//output
/*
Enter the size of array: 5
Enter the elements of array: 2 4 0 1 5
0 1 2 4 5 
*/