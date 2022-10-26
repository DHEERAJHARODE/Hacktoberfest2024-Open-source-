#include<bits/stdc++.h>
using namespace std;

int main(){
    bitset<5> bt;
    cout << "Enter input: ";
    cin >> bt;
    // all will check if all the bits are set to 0 or 1
    // if any bit is set to 0 it will return 0
    // all must be set to 1 to get 1 from bt.all()
    cout << "bt.all(): " << bt.all() << endl; // returns true or false
    cout << "bt.any(): " << bt.any() << endl; // if we have atleast single 1 we return true
    cout << "bt.count(): " << bt.count() << endl; // counts the no. if 1s
    // cout << "bt.flip(): " << bt.flip(2) << endl; // will flip the element at the given index number or flips whole bitset if no index given
    cout << "bt.none(): " << bt.none() << endl; // will return true if all bits are set to 0 and false if any single element is set to 1
    cout << "bt.set(): " << bt.set() << endl; // if index given will make that element 1 if not given will make all the elements 1 in bitset
    cout << "bt.reset(): " << bt.reset() << endl; // if index given will make that element 0 if not given will make all the elements 0 in bitset
    bt.set(0,1); // will set the element at index 0 to 1
    cout << "bt.size(): " << bt.size() << endl; // returns the size of bitset
    cout << "bt.test(): " << bt.test(0) << endl; // checks if at the given index the element is set to 1 or not
}