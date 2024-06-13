#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> mp;
    for (int i = 1; i <= 5; i++)
    {
        mp.insert({i, i * i});
    }

    // Traverse in map
    cout << "Elements in the map: " << endl;
    cout << "Value\tSquare" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }
    // Check value is present or not
    int key = 2;
    if (mp.find(key) != mp.end())
    {
        cout << key << " is present in the map." << endl;
    }
    else
    {
        cout << key << " is not present in the map." << endl;
    }

    // Erase in the map
    mp.erase(mp.begin());
    cout << "Map after deleting the first element: " << endl;
    cout << "Value\tSquare" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    // Size of the map
    cout << "The size of the map is: " << mp.size() << endl;

    // Check whether the map is empty or not
    if (mp.empty() == false)
    {
        cout << "The map is not empty." << endl;
    }
    else
    {
        cout << "The map is empty." << endl;
    }

    mp.clear();
    cout << "Now the size of the map: " << mp.size() << endl;

    return 0;
}