#include<bits/stdc++.h>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    int rows = matrix.size();
    int cols = matrix[0].size();
        
    int top = 0 , bottom = rows-1;
    int left = 0 , right = cols-1;

    while(top<=bottom && left<= right){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = spiralOrder(matrix);
    for(int n : ans){
        cout<< n << " ";
    }
    return 0;
}