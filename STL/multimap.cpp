#include <bits/stdc++.h>
using namespace std;

int main()
{
    multimap<int, int> multi_map;
    multi_map.insert({5, 5 * 2});
    multi_map.insert({3, 3 * 2});
    multi_map.insert({4, 4 * 2});
    multi_map.insert({2, 2 * 2});
    multi_map.insert({5, 5 * 2});
    multi_map.insert({4, 4 * 2});

    // Traverse through multimap
    cout << "Elements in the multimap: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = multi_map.begin(); it != multi_map.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    // Check the key is present or not
    int key = 5;
    if (multi_map.find(key) != multi_map.end())
    {
        cout << key << " is present in the multimap." << endl;
    }
    else
    {
        cout << key << " is not present in the multimap." << endl;
    }

    // Erase key in multimap
    multi_map.erase(multi_map.begin());
    cout << "Multimap after erasing the first element: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = multi_map.begin(); it != multi_map.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    // The size of the multimap
    cout << "The size of the multimap is: " << multi_map.size() << endl;

    // Check whether the multimap is empty or not
    if (multi_map.empty() == false)
    {
        cout << "The multimap is not empty." << endl;
    }
    else
    {
        cout << "The multimap is empty." << endl;
    }

    multi_map.clear();
    cout << "Now the size of the multimap: " << multi_map.size() << endl;

    return 0;
}