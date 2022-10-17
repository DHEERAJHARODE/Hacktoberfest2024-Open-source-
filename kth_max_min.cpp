#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}


int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

int quicksort(int *arr, int low, int high){
	
	if(low<high){
	int pi = partition(arr, low, high); 
  
        quicksort(arr, low, pi - 1); 
        quicksort(arr, pi + 1, high); 
	}

	return 0;
	
}

int main(){
	
	int n,k;

	cout<<"Enter N: ";
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quicksort(arr, 0,n);
	cout<<endl<<"Enter K: ";
	cin>>k;
	cout<<"Max: "<<arr[k]<<endl<<"Min: "<<arr[n-k+1];
	
	return 0;
}
