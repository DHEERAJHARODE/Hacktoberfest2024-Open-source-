#include<bits/stdc++.h>

bool Palindromic(int i, int j, string& str){
    while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else return false;
    }
    return true;
}

int partition(int i, string& str){
    if(i==str.size()) return 0;
    int mincost=INT_MAX;
    for(int j=i;j<str.size();j++){
        if(Palindromic(i,j,str)){
            int cost=1+partition(j+1,str);
            mincost=min(mincost,cost);
        }
    }
    return mincost;
}

int palindromePartitioning(string str){
    //-1 as algo cuts at end as well and counts it
    return partition(0,str)-1;
}


#include<bits/stdc++.h>

bool Palindromic(int i, int j, string& str){
    while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else return false;
    }
    return true;
}

int partition(int i, string& str, vector<int> &dp){
    if(i==str.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int mincost=INT_MAX;
    for(int j=i;j<str.size();j++){
        if(Palindromic(i,j,str)){
            int cost=1+partition(j+1,str,dp);
            mincost=min(mincost,cost);
        }
    }
    return dp[i]=mincost;
}

int palindromePartitioning(string str){
    int n=str.size();
    vector<int> dp(n,-1);
    //-1 as algo cuts at end as well and counts it
    return partition(0,str,dp)-1;
}


#include<bits/stdc++.h>

bool Palindromic(int i, int j, string& str){
    while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else return false;
    }
    return true;
}

int palindromePartitioning(string str){
    int n=str.size();
    vector<int> dp(n+1,0);//as we are doing j+1 and for i=n-1, j+1 becomes n
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int mincost=INT_MAX;
        for(int j=i;j<n;j++){
            if(Palindromic(i,j,str)){
                int cost=1+dp[j+1];
                mincost=min(mincost,cost);
            }
        }
        dp[i]=mincost;
    }
    //-1 as algo cuts at end as well and counts it
    return dp[0]-1;
}
