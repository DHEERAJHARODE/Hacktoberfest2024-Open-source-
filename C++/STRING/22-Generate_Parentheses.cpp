#include<bits/stdc++.h>
using namespace std;
vector<string> res;

void solve(string str,int a,int b,int n){
    if(a+b==n*2){
        res.push_back(str);
        return;
    }
    if(a==n){
        solve(str+')',a,b+1,n);
    }
    else if(a>b){
        solve(str+')',a,b+1,n);
        solve(str+'(',a+1,b,n);
    }
    else{ 
        solve(str+'(',a+1,b,n);
    }
}
vector<string> generateParenthesis(int n) {
    solve("(",1,0,n);
    return res;
}

int main(){
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for(auto str:ans) cout<<str<<endl;
    return 0;
}