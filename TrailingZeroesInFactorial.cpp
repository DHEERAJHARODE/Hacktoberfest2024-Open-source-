// Time complexity: Theta(logn)

#include <iostream>
using namespace std;

// effient method
int countZeroes(int n)
{
    int res = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        res += n / i;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    cout << countZeroes(n) << endl;
    return 0;
}