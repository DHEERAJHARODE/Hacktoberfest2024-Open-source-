#include <bits/stdc++.h>
using namespace std;
int calculate(string s){
    stack<int> st;
    int currentNum = 0;
    char lastOperator = '+';
    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        if (isdigit(c)){
            currentNum = currentNum * 10 + (c - '0');
        }
        if ((!isdigit(c) && !isspace(c)) || i == s.size() - 1){
            if (lastOperator == '+'){
                st.push(currentNum);
            }
            else if (lastOperator == '-'){
                st.push(-currentNum);
            }
            else if (lastOperator == '*'){
                int top = st.top();
                st.pop();
                st.push(top * currentNum);
            }
            else if (lastOperator == '/'){
                int top = st.top();
                st.pop();
                st.push(top / currentNum);
            }
            lastOperator = c;
            currentNum = 0;
        }
    }
    int res = 0;
    while (!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

int main(){
    string s = "3+2*2";
    cout << calculate(s) << endl; 
    return 0;
}