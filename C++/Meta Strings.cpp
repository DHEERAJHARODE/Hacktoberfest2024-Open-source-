Given two strings consisting of lowercase english alphabets, the task is to check whether these strings are meta strings or not. Meta strings are the strings which can be made equal by exactly one swap in any of the strings. Equal string are not considered here as Meta strings.

Example 1:

Input:
S1 = "geeks", S2 = "keegs"
Output: 1
Explanation: We can swap the 0th and 3rd
character of S2 to make it equal to S1.
â€‹Example 2:

Input: 
S1 = "geeks", S2 = "geeks"
Output: 0
Explanation: Equal strings are not considered
Meta strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function metaStrings() which takes the strings S1 and S2 as input and returns true if both the strings are meta strings, else it returns false.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105

 

Dsa-
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




bool metaStrings (string S1, string S2)
{
  
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
