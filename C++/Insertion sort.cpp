#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n) {
  // This function implements the insertion sort algorithm in c++
  int flag;
  for (int i = 1; i < n; i++) {
    flag = arr[i];
    int j = i - 1;
    // current end of array

    // move all elements larger than the flag element one position
    // ahead of in the arry upto i
    while (j >= 0 && arr[j] > flag) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = flag;
  }
}

void printArray(int arr[], int n) {
  // This fucntion will be used to print an array
  for (int i = 0; i < n; i++)
    cout << arr[i] << ",";
  cout << "\n";
}

// Driver code
int main() {
  cout << "Enter the number of elements in unsorted array\n";
  int n;

  // Take user input for size of the array
  cin >> n;

  // Declare an array of the user specified size
  int arr[n];

  // Let the user input the array
  cout << "Enter the elements of the array :\n";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  insertionSort(arr, n);
  printArray(arr, n);

  return 0;
}