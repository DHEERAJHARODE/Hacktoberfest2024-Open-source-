#include<iostream> 
#include<algorithm> 
using namespace std; 

struct Job 
{ 
char id;	 
int dead; 
int profit;
}; 


bool comparison(Job a, Job b) 
{ 
	return (a.profit > b.profit); 
} 

void printJobScheduling(Job arr[], int n) 
{ 
	sort(arr, arr+n, comparison); 

	int result[n];
	bool slot[n]; 
	for (int i=0; i<n; i++) 
		slot[i] = false; 

	for (int i=0; i<n; i++) 
	{ 

	for (int j=min(n, arr[i].dead)-1; j>=0; j--) 
	{ 
		if (slot[j]==false) 
		{ 
			result[j] = i; 
			slot[j] = true; 
			break; 
		} 
	} 
	} 


	for (int i=0; i<n; i++) 
	if (slot[i]) 
		cout << arr[result[i]].id << " "; 
} 


int main() 
{ 
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
				{'d', 1, 25}, {'e', 3, 15}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Following is maximum profit sequence of jobsn"; 
	printJobScheduling(arr, n); 
	return 0; 
} 


2.


#include <stdio.h> 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 
  
int main() 
{ 
    int n = 4;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0; 
} 
