#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                
                if(stk.empty() || (s[i] == ')' && stk.top() != '(') || (s[i] == ']' && stk.top() != '[') || (s[i] == '}' && stk.top() != '{')){
                    return false;
                }else{
                    stk.pop();
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};