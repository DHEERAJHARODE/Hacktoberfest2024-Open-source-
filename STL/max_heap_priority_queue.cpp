#include <bits/stdc++.h>
using namespace std;

/*
    MaxHeapPriorityQueue-first element is always the greatest of the elements
*/

void printPriorityQueue(priority_queue<int> pr_queue)
{
    while (!pr_queue.empty())
    {
        cout << pr_queue.top() << " ";
        pr_queue.pop();
    }
    cout << endl;
}

int main()
{
    priority_queue<int> pr_queue;
    for (int i = 1; i <= 5; i++)
    {
        pr_queue.push(i);
    }

    cout << "The elements of the priority queue are:" << endl;
    printPriorityQueue(pr_queue);

    // Size of the priority queue
    cout << "The size of the priority queue: " << pr_queue.size() << endl;

    // Front element of the priority queue
    cout << "The front element of the priority queue: " << pr_queue.top() << endl;

    // Removing the front element
    cout << "Removing the front element: " << endl;
    pr_queue.pop();

    cout << "Now the priority queue is: " << endl;
    printPriorityQueue(pr_queue);

    return 0;
}