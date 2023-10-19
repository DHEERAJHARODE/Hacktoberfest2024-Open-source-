//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends



bool metaStrings (string S1, string S2)
{
    // your code here
    if(S1==S2)return 0;
    vector<int>a;
    for(int i=0;i<(int)S2.size();i++){
        if(S1[i]!=S2[i])a.push_back(i);
    }
    if(a.size()==2){
        int x=a[0],y=a[1];
        if(S1[x]==S2[y] && S1[y]==S2[x])return 1;
    }
    return 0;
}
