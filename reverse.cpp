#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string str = "Hello, World!";
    cout << "Original string: " << str << endl;

    // Reverse the string using the reverse() function
    reverse(str.begin(), str.end());

    cout << "Reversed string: " << str << endl;

    return 0;
}
