#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<int> result;
    int left = 0, top = 0, right = col - 1, bottom = row - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
            result.push_back(mat[top][i]);
        top += 1;

        for (int i = top; i <= bottom; i++)
            result.push_back(mat[i][right]);
        right -= 1;

        if (left <= right)
        {
            for (int i = right; i >= left; i--)
                result.push_back(mat[bottom][i]);
            bottom -= 1;
        }
        if (top <= bottom)
        {
            for (int i = bottom; i >= top; i--)
                result.push_back(mat[i][left]);
            left += 1;
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}