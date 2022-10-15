#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=i;j<matrix.size();j++)
            swap(matrix[i][j],matrix[j][i]);
    }
    for(int i=0;i<matrix.size();i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main()
{
    cout<<"Enter size of square matrix ::"<<endl;
    int n;
    cin>>n;

    vector<vector<int>> a(n,vector<int>(n));

    cout<<"Enter the values::"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>a[i][j];
        }
    }

    rotate(a);
    cout<<"After rotation::"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
