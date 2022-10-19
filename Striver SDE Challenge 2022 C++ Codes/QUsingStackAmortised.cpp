#include <bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> ips,ops;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) { //push
        // Implement the enqueue() function.
        ips.push(val);
    }

    int deQueue() { //pop
        // Implement the dequeue() function.
        if(ops.empty()) {//if already some elments present then you simply pop the top
            while(!ips.empty()){
                ops.push(ips.top());
                ips.pop();
            }
        }
        int x = ops.top();
        ops.pop();
        return x;
    }

    int peek() { //top
        // Implement the peek() function here.
        if(ops.empty()) {//if already some elments present then you simply pop the top
            while(!ips.empty()){
                ops.push(ips.top());
                ips.pop();
            }
        }
        return ops.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if(ips.empty() && ops.empty()) return true;
        else return false;
    }
};