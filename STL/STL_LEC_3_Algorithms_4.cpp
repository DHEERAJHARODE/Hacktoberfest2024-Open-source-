// accumulate()
// count()
// find()
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
    // accumulate(StartIterator, EndIterator, InitialSumValue)
    cout << "sum in array: " << accumulate(arr, arr+n, 0) << endl;
    cout << "sum in STL array: " << accumulate(stl_arr.begin(), stl_arr.end(), 0) << endl;
    cout << "sum in vector: " << accumulate(vec.begin(), vec.end(), 0) << endl;

    int EC;
    cout << endl << "Enter Element to count/find: ";
    cin >> EC;

    // count(StartIterator, EndIterator, ElementToCount)
    // find(StartIterator, EndIterator, Element to find)
    cout << EC << " count in array: " << count(arr, arr+n, EC) << endl;
    cout << EC << " first occurence in array: " << (find(arr, arr+n, EC) - arr) << endl;
    cout << EC << " count in STL array: " << count(stl_arr.begin(), stl_arr.end(), EC) << endl;
    cout << EC << " first occurence in STL array: " << (find(stl_arr.begin(), stl_arr.end(), EC) - stl_arr.begin()) << endl;
    cout << EC << " count in vector: " << count(vec.begin(), vec.end(), EC) << endl;
    cout << EC << " first occurence in vector: " << (find(vec.begin(), vec.end(), EC) - vec.begin()) << endl;
}