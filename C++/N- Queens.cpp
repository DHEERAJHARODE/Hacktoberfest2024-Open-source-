** PROBLEM STATEMENT **

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
** EXAMPLE INPUT **
1. Input: n = 4
   Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
2. Input: n = 1
   Output: [["Q"]]
** CONSTRAINTS **
  1 <= n <= 9
  
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  ** SOLUTION **
  class Solution {
public:
    bool isSafe(int row, int col,vector<string> &board,int n)
    {
        //UPPER DIOGNAL
        int duprow=row,dupcol=col;//1
        while(row>=0&&col>=0)
        {
            if(board[row][col]=='Q')//2
                return false;
            row--;
            col--;
        }
        //LEFT ROW
        row=duprow,col=dupcol;//1
        while(col>=0)
        {
            if(board[row][col]=='Q')//3
                return false;
            col--;
        }
        //LOWER DIGONAL
         row=duprow,col=dupcol;//1
        while(row<n&&col>=0)//4
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
public:
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))//1
            {
               board[row][col]='Q';//1
               solve(col+1,board,ans,n);//2
               board[row][col]='.';//3
            }
        } 
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);//1
        string s(n,'.');//2
        for(int i=0;i<n;i++)
        {
            board[i]=s;//3
        }
        solve(0,board,ans,n);//4
        return ans;
    }
};
