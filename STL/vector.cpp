#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> array;

    for (int i = 1; i <= 10; i++)
    {
        array.push_back(i); // inserting elements in the vector
    }

    cout << "The elements in the vector: \n";
    for (auto it = array.begin(); it != array.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "The front element of the vector: " << array.front() << endl;
    cout << "The last element of the vector: " << array.back() << endl;
    cout << "The size of the vector: " << array.size() << endl;
    cout << "Deleting element from the end: " << array[array.size() - 1] << endl;
    array.pop_back();

    cout << "Vector after removing the last element:" << endl;
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Inserting element at the beginning:" << endl;
    array.insert(array.begin(), 5);
    cout << "The first element is: " << array[0] << endl;

    cout << "Erasing the first element: " << array[0] << endl;
    array.erase(array.begin());
    cout << "The first element is: " << array[0] << endl;

    if (array.empty())
    {
        cout << "Vector is empty" << endl;
    }
    else
    {
        cout << "Vector is not empty" << endl;
    }

    cout << "Vector's element from the end: " << endl;
    for (auto it = array.rbegin(); it != array.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    array.clear();
    cout << "The size of the vector after clearing the vector: " << array.size() << endl;

    return 0;
}