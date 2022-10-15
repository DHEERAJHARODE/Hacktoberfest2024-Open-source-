
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int numRay[] = { 0, 4, 3, 2, 4, 8, 0, 3, 1 };
	int arr_size = sizeof(numRay) / sizeof(numRay[0]);
	for (int i = 0; i < arr_size; i++) {
		numRay[numRay[i] % arr_size]
			= numRay[numRay[i] % arr_size] + arr_size;
	}
	cout << "The repeating elements are : " << endl;
	for (int i = 0; i < arr_size; i++) {
		if (numRay[i] >= arr_size * 2) {
			cout << i << " " << endl;
		}
	}
	return 0;
}

