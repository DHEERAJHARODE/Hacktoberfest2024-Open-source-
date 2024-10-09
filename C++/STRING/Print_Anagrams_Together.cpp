#include<bits/stdc++.h>
using namespace std;

vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
    unordered_map<string,vector<string>> mp;
    for(auto x : string_list){
        string word = x;
        sort(word.begin(),word.end());
        mp[word].push_back(x);
    }
    vector<vector<string>> ans;
    for(auto x : mp){
        ans.push_back(x.second);
    }
    return ans;
}

int main() {
    int N = 5;
    vector<string> words = {"act","god","cat","dog","tac"};
    vector<vector<string> > result = Anagrams(words);
    for(auto x : result) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }        
    return 0;
}