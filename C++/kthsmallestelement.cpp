#include <bits/stdc++.h>
using namespace std;

class Solution
{
     public:
    int partition(int arr[], int l, int r) {
        int pivot = arr[r];  
        int i = l;           // Place for swapping

        for (int j = l; j < r; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                swap(arr[i], arr[j]);
                i++; 
            }
        }
        swap(arr[i], arr[r]);  // Place pivot in the correct position
        return i;              
    }

    // Function to find the Kth smallest element in the array using quickselect
    int kthSmallest(int arr[], int n, int k) {
        int l = 0, r = n - 1;
        
        
        while (l <= r) {
            // Partition the array and get the pivot index
            int p = partition(arr, l, r);

            // If pivot index matches Kth smallest element
            if (p == k - 1) {
                return arr[p];
            }
            // If pivot index is greater than Kth smallest, search left
            else if (p > k - 1) {
                r = p - 1;
            }
            // If pivot index is less than Kth smallest, search right
            else {
                l = p + 1;
            }
        }
        return -1;  
    }
};


int main(){
	
	int t;
	cin >> t;
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    
	    for(int i = 0; i<n; ++i)
	        cin>>arr[i];
	        
	    Solution ob;
	    cout << ob.kthSmallest(arr, n, k) << endl;
	    
	}
	return 0;
}
