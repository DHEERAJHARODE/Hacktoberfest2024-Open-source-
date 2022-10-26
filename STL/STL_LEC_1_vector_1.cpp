#include<bits/stdc++.h>
using namespace std;

int main(){
    // vector<int> arr;
    // arr.push_back(0);
    // arr.push_back(2);
    // cout << arr.size() << endl; // 2
    // arr.pop_back(); // element 2 got removed
    // cout << arr.size() << endl; // 1
    // arr.push_back(1); arr.push_back(5); arr.push_back(3); arr.push_back(4);
    // cout << arr.size() << endl; // 5

    // // clear will delete all vector elements but will not delete the vector
    // arr.clear();
    // cout << arr.size() << endl; // 0

    // what if we want to create an vector of size x
    // vector<int> ar(4,0); // {0 0 0 0} here 4 is the size and the following is the element with which the vector needs to initialized
    // vector<int> ar1(10,5); // {5 5 5 5 5 5 5 5 5 5} size 10 intialize all elements with 5

    // copying a vector into another
    // vector<int> ar2(ar1); // {5 5 5 5 5 5 5 5 5 5}
    // vector<int> ar3 = {1,2,3,4,5,6};
    // vector<int> ar4(ar3.begin(), ar3.begin()+2); // {1,2} 2nd element is not inclusive [)

    // emplace_back is faster than push_back
    vector<int> ar5; 
    ar5.emplace_back(5);
    ar5.emplace_back(2);
    ar5.emplace_back(8);
    for(auto it=ar5.begin(); it != ar5.end(); it++){
        cout << *it << " ";
    }

}