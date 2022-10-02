#include <bits/stdc++.h>

using namespace std;

void solve(int *a, int n)
{
    set<int> s;
    for (int i = 1; i < n; ++i)
    {

        s.insert(a[i]);
    }
    auto it = s.lower_bound(a[0]);
    if (it != s.end())
        cout << *it << ' ';
    else
        cout << -1 << ' ';
}

/*
void solve(int *a, int n)
{
    set<int> s;
    int res[i];
    for(int i = n-1;i>=0;--i)
    {
        auto it = s.lower_bound(a[i]);
        if(it == s.end())
            res[i]=-1;
        else
            res[i] = *it;
        s.insert(a[i]);
    }
    for(int i=0;i<n;++i)
    cout<<res[i]<<' ';
}
*/
main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
        solve(a + i, n - i);

    return 0;
}