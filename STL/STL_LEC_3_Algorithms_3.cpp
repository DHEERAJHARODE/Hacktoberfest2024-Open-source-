// max_element()
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cout << "Enter N: ";
    cin >> n;
    int arr[n];
    array<int,5> stl_arr;
    vector<int> vec;
    for(int i=0; i<n; i++){
        cin >> x;
        arr[i] = x;
        stl_arr[i] = x;
        vec.push_back(x);
    }
    // max_element returns an iterator and we use the * to derefernce it
    cout << "Max element in array: " << *max_element(arr, arr+n) << endl;
    cout << "Max element in STL array: " << *max_element(stl_arr.begin(), stl_arr.end()) << endl;
    cout << "Max element in vector: " << *max_element(vec.begin(), vec.end()) << endl;

    // min_element returns an iterator and we use the * to derefernce it
    cout << "Min element in array: " << *min_element(arr, arr+n) << endl;
    cout << "Min element in STL array: " << *min_element(stl_arr.begin(), stl_arr.end()) << endl;
    cout << "Min element in vector: " << *min_element(vec.begin(), vec.end()) << endl;
}