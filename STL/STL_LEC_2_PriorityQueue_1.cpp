// PQ stores elements in descending order
#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << "Max PQ" << endl;
    priority_queue<int> pq;
    pq.push(1); pq.push(3); pq.push(8); pq.push(12);
    cout << pq.top() << endl; // 12
    pq.pop();
    cout << pq.top() << endl; // 8

    cout << endl << "Min PQ" << endl;
    priority_queue<int,vector<int>,greater<int>> pq1;
    pq1.push(1); pq1.push(3); pq1.push(8); pq1.push(12);
    cout << pq1.top() << endl; // 1
    pq1.pop();
    cout << pq1.top() << endl; // 3
}