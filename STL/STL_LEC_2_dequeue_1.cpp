// Deque or double ended queue
#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_front(4); // 4
    dq.push_front(3); // 3 4
    dq.push_back(5); // 3 4 5
    for(auto it = dq.begin(); it != dq.end(); it++){
        cout << *it << " ";
    } 
    cout << endl << "DQ Size: " << dq.size() << endl; // 3
    dq.pop_front(); // 4 5
    dq.pop_back(); // 4
    
    dq.emplace_front(4); dq.emplace_back(6); dq.emplace_front(3); // 3 4 4 6
    dq.erase(dq.begin()+1); // 3 4 6
    dq.clear();
    if(!dq.empty()){
        for(auto it: dq){
            cout << it << " ";
        }
    } else {
        cout << "Deque is empty" << endl;
    }


    
}