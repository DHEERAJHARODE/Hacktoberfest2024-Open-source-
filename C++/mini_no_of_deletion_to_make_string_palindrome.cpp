#include <bits/stdc++.h>
using namespace std;
int static dp[1000][1000];

int lcs(string &x, string &y,int n, int m){
    int dp[n+1][m+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
            }
            else
            dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];

}

int main(){
    string x;
    cin>>x;
    string a =x; //reverse fxn direct input string p mt lgana input ko kesi or variable m store krke uska reverse krna na k string y = reverse();
    int n=x.length();
    reverse(a.begin(),a.end());

    //just pass string and its reverse string in lcs code it give longest palindromic subsequence and no of deletion to make it palindrome are string -lps

    cout<<"no of deletion to make it palindrome are : "<<n-lcs(x,a,n,n);
}

