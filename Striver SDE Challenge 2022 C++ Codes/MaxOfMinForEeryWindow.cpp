#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> arr, int n) {
    // Write your code here.
    vector<int> ans(n+1,0);
    stack<int> st;
    vector<int> nsi(n,n);
    vector<int> psi(n,-1);
    
    //find next smaller
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and st.top()>=arr[i]) st.pop();
        if(!st.empty()) nsi[i]=st.top();
        st.push(arr[i]);
    }
    
    while(!st.empty()) st.pop();
    
    //find prev smaller
    for(int i=0;i<n;i++){
        while(!st.empty() and st.top()>=arr[i]) st.pop();
        if(!st.empty()) psi[i]=st.top();
        st.push(arr[i]);
    }

    for(int i=0;i<n;i++){
        int ind=nsi[i]-psi[i]-1;//range
        ans[ind]=max(ans[ind],arr[i]);
    }

    for(int i=n-1;i>=1;i--)
        ans[i]=max(ans[i],ans[i+1]);
    ans.erase(ans.begin(),ans.begin()+1);
    return ans;
}