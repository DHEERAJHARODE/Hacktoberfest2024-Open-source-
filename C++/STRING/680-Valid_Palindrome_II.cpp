#include<bits/stdc++.h>
using namespace std;

bool helper(string s,int i,int j){
    while(i<=j){
        if(s[i]!= s[j]) return false;
        i++;
        j--;
    }
    return true;
}
bool validPalindrome(string s) {
    int n = s.length();
    int i=0,j=n-1;
    while(i<=j){
        if(s[i]!= s[j]){
            return (helper(s, i+1, j) || helper(s, i, j-1));
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    string s = "abca";
    cout << (validPalindrome(s)? "Yes" : "No") << endl;
    return 0;
}