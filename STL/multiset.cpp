#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> multi_set;
    multi_set.insert(1);
    multi_set.insert(2);
    multi_set.insert(3);
    multi_set.insert(4);
    multi_set.insert(5);
    multi_set.insert(4);

    // Traverse through the multiset
    cout << "Elements in the multiset: " << endl;
    for (auto it = multi_set.begin(); it != multi_set.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // find value is present or not
    int key = 2;
    if (multi_set.find(key) != multi_set.end())
    {
        cout << key << " is present in multiset." << endl;
    }

    // Erasing element from the multiset
    multi_set.erase(multi_set.begin());
    cout << "Multiset after deleting the first element: " << endl;
    for (auto it = multi_set.begin(); it != multi_set.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Size of the multiset
    cout << "The size of the multiset is: " << multi_set.size() << endl;

    // check whether the multiset is empty or not
    if (multi_set.empty() == false)
    {
        cout << "The multiset is not empty. " << endl;
    }
    else
    {
        cout << "The multiset is empty." << endl;
    }
    multi_set.clear();
    cout << "The size of the multiset after clearing all the elements: " << multi_set.size() << endl;

    return 0;
}