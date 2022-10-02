#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long int x = 1ll * i * i;
        long long int ans = (1ll * x * (x - 1)) / 2 - 4 * ((i - 1) * (i - 2));
        cout << ans << endl;
    }
    return 0;
}
