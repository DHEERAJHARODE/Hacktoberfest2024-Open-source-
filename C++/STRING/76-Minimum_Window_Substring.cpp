#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int n = s.size();
    int m  =t.size();
    if(m>n) return "";
    unordered_map<char,int> orig;
    unordered_map<char,int> cnt;
    for(int i=0;i<m;i++){
        orig[t[i]]++;
        cnt[t[i]]=0;
    }

    int len = orig.size();
    int sz=0;
    int final_i =-1;
    int final_j = -1;
    int i=0;
    int j=0;
    int ans = INT_MAX;
    while(j<n){
        char temp = s[j];
        if(orig.find(temp)!=orig.end()){
            cnt[temp]++; 
            if(cnt[temp]==orig[temp]) sz++; 

            while(len==sz){ 
                if(j-i+1<=ans){
                    ans = j-i+1;
                    final_i = i;
                    final_j = j;
                }
                if(orig.find(s[i])!=orig.end()){
                    cnt[s[i]]--;
                    if(cnt[s[i]] < orig[s[i]]) sz--;
                }
                i++;
            }
        }
        j++;
    }


    if(final_i==-1 || final_j==-1) return "";
    return s.substr(final_i, final_j-final_i+1);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s,t) << endl;  // Output: "BANC"
    return 0;
}