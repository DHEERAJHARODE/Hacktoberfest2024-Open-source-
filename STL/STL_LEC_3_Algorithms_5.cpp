// binary_search()
// returns only true or false if the element exists or doesnt exist
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cout << "Enter N: ";
    cin >> n;
    int arr[n];
    array<int,9> stl_arr;
    vector<int> vec;
    for(int i=0; i<n; i++){
        cin >> x;
        arr[i] = x;
        stl_arr[i] = x;
        vec.push_back(x);
    }

    cout << "Enter element to find: ";
    cin >> x;

    // binary_search(StartIterator, EndIterator, ElementToFind)
    cout << x << " presence in array: " << binary_search(arr, arr+n, x) << endl;
    cout << x << " presence in STL array: " << binary_search(stl_arr.begin(), stl_arr.end(), x) << endl;
    cout << x << " presence in vector: " << binary_search(vec.begin(), vec.end(), x) << endl;
}