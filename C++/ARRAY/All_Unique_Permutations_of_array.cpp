#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
    sort(arr.begin(),arr.end());
    vector<vector<int>> res;
    res.push_back(arr);
    while(next_permutation(arr.begin(),arr.end())){
        res.push_back(arr);
    }
    return res;
}

int main(){
    vector<int> arr = {1, 2, 1};
    int n = arr.size();
    vector<vector<int>> res = uniquePerms(arr, n);
    for(auto &v : res){
        for(auto &x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}