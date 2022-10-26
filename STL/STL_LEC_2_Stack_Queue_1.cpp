#include<bits/stdc++.h>
using namespace std;

int main(){
    // Stack - LIFO
    stack<int> stk;
    stk.push(10);
    if(!stk.empty()){
        cout << stk.top() << endl   
             << stk.size() << endl;
    }
    stk.pop();
    if(!stk.empty()){
        cout << stk.top() << endl   
             << stk.size() << endl;
    } else {
        cout << "Stack is empty\n";
    }

    // Queue - FIFO
    queue<int> que;
    que.push(20);
    if(!que.empty()){
        cout << que.front() << endl   
             << que.size() << endl;
    }
    que.pop();
    if(!que.empty()){
        cout << que.front() << endl   
             << que.size() << endl;
    } else {
        cout << "Queue is empty\n";
    }
}