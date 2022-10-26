/* 
Iterators:
begin() -> points to the first element of the array
end() -> points after the last element of the array
rbegin() -> points to the last element of the array
rend() -> points before  first element of the array
*/ 

#include<bits/stdc++.h>
using namespace std;

int main(){
    array<int, 5> arr = { 1, 3, 4, 5, 6};
    for(auto it = arr.begin(); it!=arr.end(); it++){
        cout << *it << " ";
    } cout << endl;

    for(auto it = arr.rbegin(); it!=arr.rend(); it++){
        cout << *it << " ";
    } cout<<endl;

    // also called for-each loop
    for(auto it: arr){
        cout << it << " ";
    } cout << endl;

    string s = "arunkumar";
    for(auto c: s){
        cout << c << " ";
    } cout << endl;

    cout << arr.size() << endl;
    cout << arr.front() << " " << arr.at(0) << endl;
    cout << arr.back() << " " << arr.at(arr.size()-1) << endl;
}