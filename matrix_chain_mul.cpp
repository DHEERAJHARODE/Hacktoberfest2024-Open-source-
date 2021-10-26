#include <iostream>
#include <climits> 
using namespace std; 


int MatrixChainOrder(int *p, int n){ 

	int m[n][n]; 
	int i, j, k, L, q; 
 
	for (i = 1; i < n; i++) 
		m[i][i] = 0; 

	for (L = 2; L < n; L++) { 
		for (i = 1; i < n - L + 1; i++) { 
			j = i + L - 1; 
			m[i][j] = INT_MAX; 
			for (k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j] + 
					p[i - 1] * p[k] * p[j]; 
				if (q < m[i][j]) 
					m[i][j] = q; 
			} 
		} 
	} 

	for(int i = 1; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j < i)
				cout << " ";
			else
				cout << "\t" << m[i][j];
		}
		cout << endl; 
	}
	cout << "Minimum number of multiplications is ";
	return m[1][n - 1]; 
} 


int main(){ 
	int n;
	cout << "Enter number of matrices: ";
	cin >> n;
	int *arr = new int[n+1];
	cout << "Enter the dimensions: ";
	for(int i = 0; i < n+1; i++)
		cin >> arr[i]; 
	//int size = sizeof(arr) / sizeof(arr[0]); 
	cout << MatrixChainOrder(arr, n+1); 

	return 0; 
} 
