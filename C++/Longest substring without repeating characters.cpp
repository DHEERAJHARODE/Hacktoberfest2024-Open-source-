// C++ program to find the length of the longest 
// substring without repeating characters

#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstr(string& s) {
    int n = s.size();
    int res = 0;

    for (int i = 0; i < n; i++) {

        // Initializing all characters as not visited
        vector<bool> visited(256, false);

        for (int j = i; j < n; j++) {

            // If current character is visited
            // Break the loop
            if (visited[s[j]] == true)
                break;

            // Else update the result if this window is larger,
            // and mark current character as visited.
            else {
                res = max(res, j - i + 1);
                visited[s[j]] = true;
            }
        }
    }
    return res;
}

int main() {
    string s = "geeksforgeeks";
    cout << longestUniqueSubstr(s);
    return 0;
}
