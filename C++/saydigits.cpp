#include <iostream>
using namespace std;

void saydigit(int n, string arr[])
{
    // Base Case
    if (n == 0)
        return;

    // Recursive Call
    saydigit(n / 10, arr);

    // Processing
    int num = n % 10;
    cout << arr[num] << " ";
}

int main()
{
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int n;
    cin >> n;
    saydigit(n, arr);
}