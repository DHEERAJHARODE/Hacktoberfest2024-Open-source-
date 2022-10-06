#include<bits/stdc++.h>
using namespace std;


void build(int *segment, vector<int> &arr, int l, int r, int par) {
    if(l == r) {
        segment[par] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(segment, arr, l, mid, 2*par+1);
    build(segment, arr, mid+1, r, 2*par+2);
    segment[par] = segment[2*par+1] ^ segment[2*par+2];
}
int query(int *segment, vector<int> &arr, int l, int r, int &gl, int &gr, int par) {
    // doesn't lies in range
    if(r < gl || l > gr) return 0;
    // completely lies
    if(l >= gl && r <= gr) return segment[par];
    // overlaps
    int mid = (l+r)/2;
    int x = query(segment, arr, l, mid, gl, gr, 2*par+1);
    int y = query(segment, arr, mid+1, r, gl, gr, 2*par+2);
    return x ^ y;
}
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    int segment[4*n];
    build(segment, arr, 0, n-1, 0);
    vector<int> ans;
    for(auto it : queries) {
        int gl = it[0], gr = it[1];
        int subAns = query(segment, arr, 0, n-1, gl, gr, 0);
        ans.push_back(subAns);
    }
    return ans;
}

int main() {
    /*
    Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
    Output: [2,7,14,8] 
    Explanation: 
    The binary representation of the elements in the array are:
    1 = 0001 
    3 = 0011 
    4 = 0100 
    8 = 1000 
    The XOR values for queries are:
    [0,1] = 1 xor 3 = 2 
    [1,2] = 3 xor 4 = 7 
    [0,3] = 1 xor 3 xor 4 xor 8 = 14 
    [3,3] = 8
    */
   vector<int> arr{1,3,4,8};
   vector<vector<int>> queries{{0,1},{1,2},{0,3},{3,3}};
   vector<int> ans = xorQueries(arr, queries);
   for(auto &num : ans) {
        cout << num << " "; 
   }
   return 0;
}