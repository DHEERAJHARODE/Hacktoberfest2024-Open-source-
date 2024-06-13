/* C Program to find sum of elements 
in a given array */
#include <bits/stdc++.h> 

// function to return sum of elements 
// in an array of size n 
int sum(int arr[], int n) 
{ 
	int sum = 0; // initialize sum 

	// Iterate through all elements 
	// and add them to sum 
	for (int i = 0; i < n; i++) 
	sum += arr[i]; 

	return sum; 
} 

int main() 
{ 
	int arr[] = {12, 3, 4, 15}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printf("Sum of given array is %d", sum(arr, n)); 
	return 0; 
} 
