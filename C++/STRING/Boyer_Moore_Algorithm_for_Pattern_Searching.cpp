#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
void badCharHeuristic(string str, int size,int badchar[NO_OF_CHARS])
{
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
 
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}
void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
 
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);
 
    int s = 0; 
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0) {
            cout << "pattern occurs at shift = " << s<< endl;

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
 
        else s += max(1, j - badchar[txt[s + j]]);
    }
}
 
int main()
{
    string txt = "ABAAABCD";
    string pat = "ABC";
    search(txt, pat);
    return 0;
}