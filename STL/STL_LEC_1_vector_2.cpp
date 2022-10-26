#include<bits/stdc++.h>
using namespace std;

int main(){
    // 2d array
    vector<vector<int>> arr;

    vector<int> ar1;
    ar1.emplace_back(1);
    ar1.emplace_back(2);
    ar1.emplace_back(3);

    vector<int> ar2;
    ar2.emplace_back(4);
    ar2.emplace_back(5);
    ar2.emplace_back(6);

    vector<int> ar3;
    ar3.emplace_back(7);
    ar3.emplace_back(8);
    ar3.emplace_back(9);

    arr.push_back(ar1);
    arr.push_back(ar2);
    arr.push_back(ar3);

    for(auto vectr: arr){
        for(auto it: vectr){
            cout << it << " ";
        } cout << endl;
    }

    // 2D vector 10x20
    vector<vector<int>> vec2d(10, vector<int> (20,0));

    // 3D vector 10x20x30
    vector<vector<vector<int>>> vec3d(10, vector<vector<int>> (20, vector<int> (30, 0)));
}