#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = mat.size();
    int m = mat[0].size();

    // Transpose of a Matrix
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }

    // Reverse Row wise of a Matrix

    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(mat[i][j],mat[i][n-j-1]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}