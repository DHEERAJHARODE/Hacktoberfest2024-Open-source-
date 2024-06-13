#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialize the set
    set<int> st;
    for (int i = 1; i <= 10; i++)
    {
        st.insert(i);
    }

    // Traverse through the set
    cout << "Elements in the set: " << endl;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Find value in the set
    int temp = 2;
    if (st.find(temp) != st.end())
    {
        cout << temp << " is present in the set." << endl;
    }
    else
    {
        cout << temp << " is not present in the set." << endl;
    }

    // Erasing value from the set
    st.erase(st.begin());
    cout << "Set after deleting the first element: " << endl;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Find size of the set
    cout << "The size of the set is: " << st.size() << endl;

    // Check set is empty or not
    if (st.empty() == true)
    {
        cout << "The set is empty." << endl;
    }
    else
    {
        cout << "The set is not empty. " << endl;
    }

    st.clear();
    cout << "Size of the set after clearing all the elements: " << st.size() << endl;

    return 0;
}