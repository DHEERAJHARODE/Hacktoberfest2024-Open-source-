#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<int> st;
    for (char ch : s){
        if (ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }
        else{
            if (st.empty()) return false;
            if ((ch == ')' && st.top() != '(') ||
                (ch == ']' && st.top() != '[') ||
                (ch == '}' && st.top() != '{')){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s = "()[]{}";
    if (isValid(s)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}