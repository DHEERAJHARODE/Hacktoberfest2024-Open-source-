#include<bits/stdc++.h>
void sortedInsert(stack<int> &stack, int key)  
{  
    // base case: if the stack is empty or the key is greater than all elements in the stack  
    if (stack.empty() || key > stack.top()){  
        stack.push(key);  
        return;  
    }

    /* We reach here when the key is smaller than the top element */  
    // remove the top element  
    int top = stack.top();  
    stack.pop();  
    // recur for the remaining elements in the stack  
    sortedInsert(stack, key);  

    // insert the popped element back into the stack  
    stack.push(top);  
}  
   
// Recursive method to sort a stack  
void sortStack(stack<int> &stack)
{  
    // base case: stack is empty  
    if (stack.empty()) return;

    // remove the top element  
    int top = stack.top();  
    stack.pop();  
    // recur for the remaining elements in the stack  
    sortStack(stack);  

    // insert the popped element back into the sorted stack  
    sortedInsert(stack, top);  
}  