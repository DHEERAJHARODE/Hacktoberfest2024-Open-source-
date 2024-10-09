#include <bits/stdc++.h>
using namespace std;

vector<char> printDuplicates(string &s) {
    unordered_map<char, int> freq;
    unordered_set<char> added; 
    vector<char> ans;
    for (char c : s) {
        freq[c]++;
    }

    for (char c : s) {
        if (freq[c] > 1 && added.find(c) == added.end()) {
            ans.push_back(c);
            added.insert(c);  
        }
    }
    return ans;
}

int main() {
    string str = "aabccdeef";
    vector<char> duplicates = printDuplicates(str);
    
    if (duplicates.empty()) {
        cout << "No duplicates found" << endl;
    } else {
        cout << "Duplicates: ";
        for (char c : duplicates)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}
