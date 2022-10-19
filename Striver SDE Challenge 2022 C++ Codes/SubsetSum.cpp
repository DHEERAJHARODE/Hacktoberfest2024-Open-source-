#include <bits/stdc++.h>
void ss(int i, int sum, int n, vector<int> &num, vector<int> &ans){
    if(i==n) {
        ans.push_back(sum);
        return;
    }
    //we either select elem at i or not. Do this for all elems.
    //selection means adding it to sum
    ss(i+1,sum+num[i],n,num,ans); //select elem at i
    ss(i+1,sum,n,num,ans);// dont select
}
    
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    ss(0,0,num.size(),num,ans);
    sort(ans.begin(),ans.end());
    return ans;
}