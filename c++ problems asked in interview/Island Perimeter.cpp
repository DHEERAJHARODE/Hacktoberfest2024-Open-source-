// Leetcode problem asked in interviews ----> https://leetcode.com/problems/island-perimeter/

// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Input:
// row = 4, col=4
// grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16

// Input: 
// row = 1,col =1
// grid = [[1]]
// Output: 4

//Input:
// row = 1, col = 2 
// grid = [[1,0]]
// Output: 4


// Constraints:

// row == grid.length
// col == grid[i].length
// 1 <= row, col <= 100
// grid[i][j] is 0 or 1.
// There is exactly one island in grid.


// Category ---> Array, DFS, BFS, Matrix



#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int islands = 0;
    int neighbors = 0;

    for (int i = 0; i <(int)grid.size(); ++i)
      for (int j = 0; j <(int) grid[0].size(); ++j)
        if (grid[i][j]) {
          ++islands;
          if (i - 1 >= 0 && grid[i - 1][j])
            ++neighbors;
          if (j - 1 >= 0 && grid[i][j - 1])
            ++neighbors;
        }

    return islands * 4 - neighbors * 2;
  }
};

signed main(){
	int row,col;
	cin >> row >> col;
	vector<vector<int>> grid(row,vector<int>(col));
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin >> grid[i][j];
		}
	}
	Solution *obj = new Solution();
	cout << obj->islandPerimeter(grid) << "\n";
	return 0;
}

// Time Complexity : O(mn)
// Space Complexity : O(1)