#include <bits/stdc++.h>
using namespace std;

void transpose(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void reverse(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int x = col - 1;
        for (int j = 0; j < col/2; j++)
        {
            swap(arr[i][j], arr[i][x]);
            x--;
        }
    }
}
int main()
{

    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout<<"Real Array \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"\n The Transposed Array Looks like\n\n";
    transpose(arr, 3, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"\n\nFinal Array \n\n";
    reverse(arr, 3, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}