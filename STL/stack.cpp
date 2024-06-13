#include <bits/stdc++.h>
using namespace std;

/*

STACK -> Last-In-First-Out=>LIFO

*/

void printStack(stack<int> stk)
{
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(5);
    stk.push(3);
    stk.push(6);
    stk.push(2);

    cout << "The elements of the stack are:" << endl;
    printStack(stk);

    // Size of the stack
    cout << "The size of the stack: " << stk.size() << endl;

    // Top element of the stack
    cout << "The top element of the stack: " << stk.top() << endl;

    // Remove the top element
    cout << "Removing the top element: " << endl;
    stk.pop();

    // Insert into the stack
    cout << "Inserting into the stack." << endl;
    stk.emplace(9);

    cout << "Now the stack is: " << endl;
    printStack(stk);

    // Check the stack is empty or not
    if (stk.empty())
    {
        cout << "The stack is empty." << endl;
    }
    else
    {
        cout << "The stack is not empty." << endl;
    }

    return 0;
}