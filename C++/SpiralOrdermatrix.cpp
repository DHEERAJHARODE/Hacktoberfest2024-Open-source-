#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    

    // sprial order printing logic

    int row_s =0,row_e=n-1,column_s=0,column_e =m-1;
    while(row_s<=row_e && column_s<=column_e){
        for(int col =column_s;col<=column_e;col++){
            cout<<a[row_s][col]<<" ";
        }
        row_s++;

        for(int row = row_s;row<=row_e;row++){
            cout<<a[row][column_e]<<" ";
        }
        column_e--;


        for(int col=column_e;col>=column_s;col--){
            cout<<a[row_e][col]<<" ";
        }
        row_e--;
        for(int row=row_e;row>=row_s;row--){
            cout<<a[row][column_s]<<" ";
        }
        column_s++;

    }
    return(0);
}