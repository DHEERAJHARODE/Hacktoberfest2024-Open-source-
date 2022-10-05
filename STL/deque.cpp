#include <bits/stdc++.h>
using namespace std;

/*
    DEQUE- Double Ended Queue
*/

void printDeque(deque<int> Deque)
{
    for (auto it = Deque.begin(); it != Deque.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> Deque;
    Deque.push_back(10);
    Deque.push_back(20);
    Deque.push_front(30);
    Deque.push_front(40);
    Deque.push_front(50);
    Deque.push_front(70);

    cout << "The elements in the deque are: " << endl;
    printDeque(Deque);

    // Size of the deque
    cout << "The size of the deque is: " << Deque.size() << endl;

    // Front element of the deque
    cout << "The front element in the deque: " << Deque.front() << endl;

    // Removing the front element
    cout << "Removing the front element" << endl;
    Deque.pop_front();
    printDeque(Deque);

    // Removing the last element
    cout << "The last element of the deque: " << Deque.back() << endl;
    cout << "Removing the last element." << endl;
    Deque.pop_back();

    // Resize the deque
    cout << "Resizing the deque." << endl;
    Deque.resize(3);

    cout << "Now the deque is: " << endl;
    printDeque(Deque);

    return 0;
}