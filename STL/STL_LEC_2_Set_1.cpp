// A set has only unique elements 
// The first element is the smallest and the 2nd element is the 2nd smallest element (continued trend)
// an unordered set has elements in random order (No ascending) and elements are still unique here
// In a multiset the elements are stored in ascending fashion and we can have multiple instances of a same element


#include<bits/stdc++.h>
using namespace std;

int main(){
    // set<int> st;

    // int n,x=0;
    // cin >> n;
    // for(int i=0; i<n; i++){
    //     cin >> x;
    //     st.insert(x);
    // }
    
    // st.erase(st.begin()); // will remove the first element in the set (the smallesto one)
    // st.erase(5); // will remove the element specified

    // new code below

    // set<int> st1 = {5,2,1,4,3}; // the order doesnt matter it will be in ascending only
    // auto it1 = st1.find(2);
    // for(auto it=st1.begin(); it!= st1.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << "\nsize of the set before erase: " << st1.size() << endl;
    // st1.erase(it1); // iterator pointing to the element specified
    
    // for(auto it=st1.begin(); it!= st1.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl << "size of the set after erase: " << st1.size() << endl;

    //new code below
    // set<int> st2 = {5,2,1,4,3};
    // for(auto it: st2){
    //     cout << it << " ";
    // }

    // unordered set
    // unordered_set<int> ust;
    // unordered_set<int> ust1 = {9,4,1}; // 9 4 1
    // ust.emplace(5); // 5
    // ust.insert(21); // 5 21
    // ust.emplace(9); // 5 21 9

    // ust.erase(21); // 9 5
    // ust1.erase(ust1.find(9)); // 4 1
    // for(auto it: ust1){
    //     cout << it << " ";
    // }

    // Multiset
    multiset<int> ms;
    ms.insert(8);
    ms.emplace(6);
    ms.insert(6);
    ms.emplace(5); // 5 6 6 8

    ms.size(); // 4

    ms.erase(ms.begin()); // 6 6 8
    ms.erase(ms.find(6)); // 6 8

    ms.size(); // 2
}