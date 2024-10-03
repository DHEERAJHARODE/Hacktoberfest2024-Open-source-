
// Solution 1: Recursion

// Intuition:

// The best way to solve such problems is using recursion.

// Approach:

// 1)Start at the source(0,0) with an empty string and try every possible path i.e upwards(U), downwards(D),   leftwards(L) and rightwards(R).  

// 2)As the answer should be in lexicographical order so it's better to try the directions in lexicographical order i.e (D,L,R,U)

// 3)Declare a 2D-array named visited because the question states that a single cell should be included only once in the path,so it's important to keep track of the visited cells in a particular path.

// 4)If a cell is in path, mark it in the visited array.

// 5)Also keep a check of the “out of bound” conditions while going in a particular direction in the matrix. 

// 6)Whenever you reach the destination(n,n) it's very important to get back as shown in the recursion tree.

// 7)While getting back, keep on unmarking the visited array for the respective direction.Also check whether there is a different path possible while getting back and if yes, then mark that cell in the visited array. 


// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.

// Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).


#include <bits/stdc++.h>

using namespace std;

class Solution {
  void findPathHelper(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    // downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
      vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));

      if (m[0][0] == 1) findPathHelper(0, 0, m, n, ans, "", vis);
      return ans;
    }
};

int main() {
  int n = 4;

   vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

  Solution obj;
  vector < string > result = obj.findPath(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}


