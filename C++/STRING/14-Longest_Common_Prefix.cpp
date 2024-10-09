#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs){
    sort(strs.begin(), strs.end());
    string ans="";
    string firstElement = strs[0] , lastElement = strs[strs.size()-1];
    int len = min(firstElement.size(),lastElement.size());
    for(int i=0;i<len;i++){
        if(firstElement[i]!= lastElement[i]) return ans;
        ans += firstElement[i];
    }
    return ans;
}

int main(){
    vector<string> v = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(v) << endl;
    return 0;
}