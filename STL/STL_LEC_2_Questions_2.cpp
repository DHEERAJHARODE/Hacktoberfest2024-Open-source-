// given N elements, print all the elements in sorted order
// input
// 6
// 6 6 3 2 3 5

// output
// 2 3 3 5 6 6

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    multiset<int> ms;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        ms.insert(x);
    }
    for(auto it: ms){
        cout << it << " ";
    }
}