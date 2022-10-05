#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> un_map;
    un_map.insert({8, 8 * 8});
    un_map.insert({3, 3 * 3});
    un_map.insert({1, 1 * 1});
    un_map.insert({5, 5 * 5});
    un_map.insert({6, 6 * 6});

    // Traverse in the unordered map
    cout << "Elements in the unordered map: " << endl;
    cout << "Value\tSquare" << endl;
    for (auto it = un_map.begin(); it != un_map.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }
    // Check value is present or not
    int key = 2;
    if (un_map.find(key) != un_map.end())
    {
        cout << key << " is present in unordered map." << endl;
    }
    else
    {
        cout << key << " is not present in unordered map." << endl;
    }
    // Erase in the unordered map
    un_map.erase(un_map.begin());
    cout << "unordered map after deleting the first element: " << endl;
    cout << "Value\tESquare" << endl;
    for (auto it = un_map.begin(); it != un_map.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    // Size of the unordered map
    cout << "The size of the unordered map is: " << un_map.size() << endl;

    // Check whether the unordered map is empty or not
    if (un_map.empty() == false)
    {
        cout << "The unordered map is not empty." << endl;
    }
    else
    {
        cout << "The unordered map is empty." << endl;
    }

    un_map.clear();
    cout << "Now the size of the unordered map: " << un_map.size() << endl;

    return 0;
}