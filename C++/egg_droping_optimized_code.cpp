#include <bits/stdc++.h>
using namespace std;
int dp[20][100];
int solve(int e, int f){
    
    if(e==1){return f;}
    if(f==0 || f==1){
        return f;
    }
    if(dp[e][f]!=-1){
        return dp[e][f];}

    int mini =INT_MAX;
    int temp=0;
    int low,high;

    

    for(int k=1;k<=f;k++){

        if(dp[e-1][k-1]!=-1){
         low = dp[e-1][k-1]; }
        else{ 
            low = solve(e-1,k-1);
            dp[e-1][k-1]=low;}

        if(dp[e][f-k]!=-1){
        high = dp[e][f-k]; }
        else{ 
            high = solve(e,f-k);
            dp[e][f-k]=high;}
            
          temp =1+max(low,high);
          mini = min(mini,temp);
    }
    
    return dp[e][f]=mini;

}

int main(){

int e,f;
memset(dp,-1,sizeof(dp));
cin>>e>>f;
cout<<solve(e,f);
}