#include <iostream>
using namespace std;

int stairclimb(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    // R.C
    return stairclimb(n - 1) + stairclimb(n - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << stairclimb(n) << " ";
    return 0;
}