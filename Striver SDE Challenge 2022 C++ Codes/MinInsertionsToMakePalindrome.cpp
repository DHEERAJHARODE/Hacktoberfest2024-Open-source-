#include<bits/stdc++.h>
int lcs(string s, string t)
{
    int n=s.size(),m=t.size();
    vector<int> prev(m+1,0), cur(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) cur[j]=prev[j-1]+1;
            else cur[j]=max(cur[j-1],prev[j]);
        }
        prev=cur;
    }
    return prev[m];
}

int minInsertion(string &str) {
    string t=str;
    reverse(t.begin(),t.end());
    return str.size()-lcs(str,t);
}
