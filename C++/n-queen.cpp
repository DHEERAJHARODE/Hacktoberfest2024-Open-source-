#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Display(vector<vector<int>> &arr)
{
    for (auto row : arr)
    {
        for (auto num : row)
        {
            if (num)
                cout << "Q ";
            else
                cout << "X ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> &arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (arr[i][col])
        {
            return false;
        }
    }
    int DiagLeft = min(row, col);
        for (int i = 1; i <= DiagLeft; i++)
        {
            if (arr[row - i][col - i])
                return false;
        }

        int size = arr.size() - 1;
        int DiagRight = min(row, size - col);
        for (int i = 1; i <= DiagRight; i++)
        {
            if (arr[row - i][col + i])
                return false;
        }
    return true;
}

int CountWays(vector<vector<int>> &board, int row)
{
    if (row == board.size())
    {
        Display(board);
        return 1;
    }
    int count = 0; // count the number of ways!!1
    for (int i = 0; i < board[0].size(); i++)
    {
        if (isSafe(board, row, i))
        {
            board[row][i] = true;
            count += CountWays(board, row + 1);
            board[row][i] = false;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr =
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}};

    cout << "Queens can be placed in " << CountWays(arr, 0) << " ways";

    return 0;
}
