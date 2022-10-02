#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int x, y;
        cin >> y >> x;
        long long int ans = 0;
        if (y >= x)
        {
            if (y % 2 == 0)
                ans = y * y - x + 1;
            else
                ans = (y - 1) * (y - 1) + x;
        }
        else
        {
            if (x % 2 != 0)
                ans = x * x - y + 1;
            else
                ans = (x - 1) * (x - 1) + y;
        }
        cout << ans << endl;
    }
    return 0;
}
