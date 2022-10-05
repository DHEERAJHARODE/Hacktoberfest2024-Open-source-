#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialize the unordered set
    unordered_set<int> un_set;
    for (int i = 10; i > 0; i--)
    {
        // un_set.insert(i);
        un_set.emplace(i);
    }

    // Traverse through the unordered set
    cout << "Elements in the unordered set: " << endl;
    for (auto it = un_set.begin(); it != un_set.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Find value in the unordered set
    int temp = 2;
    if (un_set.find(temp) != un_set.end())
    {
        cout << temp << " is present in the unordered set." << endl;
    }
    else
    {
        cout << temp << " is not present in the unordered set." << endl;
    }

    // Erasing value from the unordered set
    un_set.erase(un_set.begin());
    cout << "unordered set after deleting the first element: " << endl;
    for (auto it = un_set.begin(); it != un_set.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Find size of the unordered set
    cout << "The size of the unordered set is: " << un_set.size() << endl;

    // Check unordered set is empty or not
    if (un_set.empty() == true)
    {
        cout << "The unordered set is empty." << endl;
    }
    else
    {
        cout << "The unordered set is not empty. " << endl;
    }

    un_set.clear();
    cout << "Size of the unordered set after clearing all the elements: " << un_set.size() << endl;

    return 0;
}