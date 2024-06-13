#include <bits/stdc++.h>
using namespace std;

/*
    QUEUE->First-In-First-Out=> FIFO
*/

void printQueue(queue<int> Queue)
{
    while (!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> Queue;
    for (int i = 1; i <= 6; i++)
    {
        Queue.emplace(i);
    }

    cout << "The elements of the queue are: " << endl;
    printQueue(Queue);

    // Size of the queue
    cout << "The size of the queue: " << Queue.size() << endl;

    // Front element of the queue
    cout << "The front element of the queue: " << Queue.front() << endl;

    // Last element of the queue
    cout << "The last element of the queue: " << Queue.back() << endl;

    // Removing the element
    cout << "Removing the front element: " << endl;
    Queue.pop();
    printQueue(Queue);

    // Check the queue is empty or not
    if (Queue.empty())
    {
        cout << "The queue is empty." << endl;
    }
    else
    {
        cout << "The queue is not empty." << endl;
    }

    return 0;
}