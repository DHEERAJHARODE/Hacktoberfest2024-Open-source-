#include <bits/stdc++.h>
using namespace std;

long long int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    long long int res = 1;
    long long int x = 2;
    while (n > 0)
    {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n = n / 2;
    }
    cout << res << endl;
    return 0;
}
