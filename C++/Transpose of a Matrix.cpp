#include<iostream>
using namespace std;
int main()
{
    int mat[10][10], matT[10][10];
    int matRow, matCol, i, j;
    cout<<"Enter Row and Column Size of Matrix: ";
    cin>>matRow>>matCol;
    cout<<"Enter "<<matRow*matCol<<" Elements for "<<matRow<<"*"<<matCol<<" Matrix: ";
    for(i=0; i<matRow; i++)
    {
        for(j=0; j<matCol; j++)
            cin>>mat[i][j];
    }
    cout<<"\nOriginal Matrix is:\n";
    for(i=0; i<matRow; i++)
    {
        for(j=0; j<matCol; j++)
            cout<<mat[i][j]<<"  ";
        cout<<endl;
    }
    // copying the transpose of given matrix to matT[][]
    for(i=0; i<matRow; i++)
    {
        for(j=0; j<matCol; j++)
            matT[j][i] = mat[i][j];
    }
    cout<<"\nTranspose of Given Matrix is:\n";
    for(i=0; i<matCol; i++)
    {
        for(j=0; j<matRow; j++)
            cout<<matT[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
