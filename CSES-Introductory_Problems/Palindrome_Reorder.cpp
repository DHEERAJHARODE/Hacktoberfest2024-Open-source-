#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> v(26, 0);
    for (char c : s)
        v[c - 'A']++;
    string output = "";
    bool odd = false;
    char c = '!';
    for (int i = 0; i < 26; i++)
        if (v[i] % 2 != 0)
        {
            if (odd == false)
            {
                for (int j = 0; j < v[i] / 2; j++)
                    output += 'A' + i;
                odd = true;
                c = 'A' + i;
            }
            else
            {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
        else
        {
            for (int j = 0; j < v[i] / 2; j++)
                output += 'A' + i;
        }
    string rev = string(output.rbegin(), output.rend());
    if (c != '!')
        output += (c + rev);
    else
        output += rev;
    cout << output << endl;
    return 0;
}