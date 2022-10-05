#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_multimap<int, int> unmulti_map;
    unmulti_map.insert({5, 5 * 3});
    unmulti_map.insert({3, 3 * 3});
    unmulti_map.insert({4, 4 * 3});
    unmulti_map.insert({2, 2 * 3});
    unmulti_map.insert({5, 5 * 3});
    unmulti_map.insert({4, 4 * 3});

    // Traverse through unordered multimap
    cout << "Elements in the unordered multimap: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = unmulti_map.begin(); it != unmulti_map.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    // Check the key is present or not
    int key = 5;
    if (unmulti_map.find(key) != unmulti_map.end())
    {
        cout << key << " is present in the unordered multimap." << endl;
    }
    else
    {
        cout << key << " is not present in the unordered multimap." << endl;
    }

    // Erase key in unordered multimap
    unmulti_map.erase(unmulti_map.begin());
    cout << "unordered multimap after erasing the element: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = unmulti_map.begin(); it != unmulti_map.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    // The size of the unordered multimap
    cout << "The size of the unordered multimap is: " << unmulti_map.size() << endl;

    // Check whether the unordered multimap is empty or not
    if (unmulti_map.empty() == false)
    {
        cout << "The unordered multimap is not empty." << endl;
    }
    else
    {
        cout << "The unordered multimap is empty." << endl;
    }

    unmulti_map.clear();
    cout << "Now the size of the unordered multimap: " << unmulti_map.size() << endl;

    return 0;
}