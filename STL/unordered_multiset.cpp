#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_multiset<int> unmulti_set;
    unmulti_set.insert(1);
    unmulti_set.insert(2);
    unmulti_set.insert(3);
    unmulti_set.insert(3);
    unmulti_set.insert(4);
    unmulti_set.insert(5);
    unmulti_set.insert(4);

    // Traverse through the unordered multiset
    cout << "Elements in the unordered multiset: " << endl;
    for (auto it = unmulti_set.begin(); it != unmulti_set.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // find value is present or not
    int key = 2;
    if (unmulti_set.find(key) != unmulti_set.end())
    {
        cout << key << " is present in unordered multiset." << endl;
    }

    // Erasing element from the unordered multiset
    unmulti_set.erase(unmulti_set.begin());
    cout << "Multiset after deleting the first element: " << endl;
    for (auto it = unmulti_set.begin(); it != unmulti_set.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Size of the unordered multiset
    cout << "The size of the unordered multiset is: " << unmulti_set.size() << endl;

    // check whether the unordered multiset is empty or not
    if (unmulti_set.empty() == false)
    {
        cout << "The unordered multiset is not empty. " << endl;
    }
    else
    {
        cout << "The unordered multiset is empty." << endl;
    }
    
    unmulti_set.clear();
    cout << "The size of the unordered multiset after clearing all the elements: " << unmulti_set.size() << endl;

    return 0;
}