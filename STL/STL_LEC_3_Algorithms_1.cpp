// Sort()
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cout << "Enter N: ";
    cin >> n;
    array<int,5> arr,arr1;
    vector<int> vec,vec1;
    for(int i=0; i<n; i++){
        cin >> x;
        arr[i] = x;
        vec.push_back(x);
    }
    arr1 = arr;
    vec1 = vec;
    cout << "array before sort: ";
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    } cout << endl;
    cout << "vector before sort: ";
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    } cout << endl;

    sort(arr.begin(), arr.end()); // array sort
    sort(vec.begin(), vec.end()); // vector sort

    cout << "array after sort: ";
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    } cout << endl;
    cout << "vector after sort: ";
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    } cout << endl;

    cout << "sorting between 2nd and last-1 element" << endl;

    sort(arr1.begin()+1, arr1.end()-1);
    sort(vec1.begin()+1, vec1.end()-1);
    cout << "array " << endl;
    for(auto it = arr1.begin(); it != arr1.end(); it++){
        cout << *it << " ";
    } cout << endl;
    cout << "vector" << endl;
    for(auto it = vec1.begin(); it != vec1.end(); it++){
        cout << *it << " ";
    } cout << endl;

}