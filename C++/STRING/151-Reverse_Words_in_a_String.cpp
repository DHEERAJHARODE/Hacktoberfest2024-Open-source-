#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    stack<string> st;
    string word = "";
    string ans = "";
    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            if(!word.empty()){
                st.push(word);
                word="";
            }
        }
        else{
            word+=s[i];
        }
    }
    if(!word.empty()) st.push(word);
    while(st.size() != 1){
        ans += st.top() + " ";
        st.pop();
    }
    ans += st.top();
    return ans;
}

int main(){
    string s = "the sky is blue";
    cout << reverseWords(s) << endl;
    return 0;
}