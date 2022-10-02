#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    set<string> perms;
    sort(s.begin(), s.end());
    perms.insert(s);
    while (next_permutation(s.begin(), s.end()))
        perms.insert(s);
    cout << perms.size() << endl;
    for (string x : perms)
        cout << x << endl;
    return 0;
}
