#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
    int c1=0,c2=0,e1=0,e2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==e1) c1++;
        else if(arr[i]==e2) c2++;
        else if(c1==0){e1=arr[i],c1++;}
        else if(c2==0){e2=arr[i],c2++;}
        else{c1--,c2--;}
    }
    c1=0,c2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==e1) c1++;
        else if(arr[i]==e2) c2++;
    }
    if(c1>arr.size()/3) ans.push_back(e1);
    if(c2>arr.size()/3) ans.push_back(e2);
    return ans;
}