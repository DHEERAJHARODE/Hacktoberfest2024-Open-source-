// reverse()
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cout << "Enter N: ";
    cin >> n;
    array<int,5> arr;
    vector<int> vec;
    for(int i=0; i<n; i++){
        cin >> x;
        arr[i] = x;
        vec.push_back(x);
    }
    
    reverse(arr.begin(), arr.end()); // array reverse
    reverse(vec.begin(), vec.end()); // vector reverse

    cout << "array after reverse: ";
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    } cout << endl;
    cout << "vector after reverse: ";
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    } cout << endl;

    cout << "reversing between 2nd and last-1 element" << endl;

    reverse(arr.begin()+1, arr.end()-1);
    reverse(vec.begin()+1, vec.end()-1);
    cout << "array: ";
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    } cout << endl;
    cout << "vector: ";
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    } cout << endl;
}