#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();
    int cell00=1;
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0)
                cell00=0;
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //we traverse from bottom to up as if row0 is set to 0 then in any (i+k)th row that has not to be set 0, it'd be set 0 as row0 would be 0 as row0 is check row
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(cell00==0)
                matrix[i][0]=0;
        }
}