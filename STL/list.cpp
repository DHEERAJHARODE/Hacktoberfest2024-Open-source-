#include <bits/stdc++.h>
using namespace std;

void printlist(list<int> li)
{
    list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    list<int> li;
    li.push_back(10);
    li.push_back(20);
    li.push_front(30);
    li.push_front(40);
    li.push_front(50);

    // Traverse the list
    cout << "The list is: " << endl;
    printlist(li);

    // Reverse the list
    cout << "Reversing the list: " << endl;
    li.reverse();
    printlist(li);

    // Sort the list
    cout << "Sorting the list: " << endl;
    li.sort();
    printlist(li);

    // Size of the list
    cout << "The size of the list is: " << li.size() << endl;

    // First element of the list
    cout << "The first element in the list: " << li.front() << endl;

    // Erasing the element
    cout << "Erasing the first element." << endl;
    li.pop_front();
    printlist(li);

    // Last element of the list
    cout << "The last element of the list: " << li.back() << endl;
    cout << "Erasing the last element." << endl;
    li.pop_back();
    printlist(li);

    // Insert in front of the list
    cout << "Insert in front of the list." << endl;
    li.emplace_front(9);

    // Insert from back of the list
    cout << "Insert from back of the list." << endl;
    li.emplace_back(6);

    cout << "Now the list is: " << endl;
    printlist(li);

    return 0;
}