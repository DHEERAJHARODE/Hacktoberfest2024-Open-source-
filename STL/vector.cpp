#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Assign vector
    vector<int> vect;

    // fill the vector with 5 ten times
    vect.assign(10, 5);

    // Get the size of the vector
    int vector_size = vect.size();

    // Iterate the vector using for loop
    cout << "Vector elements are\n";
    for (int i = 0; i < vector_size; i++)
    {
        cout << vect[i] << " ";
    }
    // inserts 20 to the last position
    vect.push_back(20);
    vector_size = vect.size();
    cout << "\nThe last element after insert new element is: " << vect[vector_size - 1];

    // removes last element
    vect.pop_back();
    // Print the vector
    cout << "\nThe vector elements after removing the last element are: ";
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }

    // inserts 8 at the beginning
    vect.insert(vect.begin(), 8);
    cout << "\nThe first element is: " << vect[0];

    // removes the first element
    vect.erase(vect.begin());
    cout << "\nThe first element is: " << vect[0];
    return 0;
}
