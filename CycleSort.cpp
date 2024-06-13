// Cycle sort is a comparison sorting algorithm that forces array to be factored into the number of cycles where each of them can be rotated to produce a sorted array

#include<bits/stdc++.h>

using namespace std;

void cyclic_Sort(int arr[], int size) {
  int i = 0;
  while (i < size) {
    int position = arr[i] - 1;
    if (arr[i] != arr[position]) {
      swap(arr[i], arr[position]);
    } else {
      i++;
    }
  }

}

void printer(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) cout << arr[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>name;
  int arr[] = {3,2,4,5,1};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Before sorting array: \n";
  printer(arr, n);cyclic_Sort(arr, n);
  cout << "Sorted array: \n";
  printer(arr, n);
  return 0;

}
