#include<bits/stdc++.h>
using namespace std;

bool isValidNeighbour(int x, int y, vector<vector<int>>& board) {    return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());}

void gameOfLife(vector<vector<int>>& board) {
    vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
    vector<int> dy = {1, -1, -1, 0, 1, 1, 0, -1};
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            int liveNeighbours = 0;
            for (int i = 0; i < 8; i++) {
                int curr_r = row + dx[i], curr_c = col + dy[i];
                if (isValidNeighbour(curr_r, curr_c, board) && abs(board[curr_r][curr_c]) == 1) {
                    liveNeighbours++;
                }
            }
            if (board[row][col] == 1 && (liveNeighbours < 2 || liveNeighbours > 3)) {
                board[row][col] = -1;
            }
            if (board[row][col] == 0 && liveNeighbours == 3) {
                board[row][col] = 2;
            }
        }
    }

    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            if (board[row][col] > 0) {
                board[row][col] = 1;
            } else {
                board[row][col] = 0;
            }
        }
    }
    
}
int main(){
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    gameOfLife(board);
    for(auto row: board){
        for(auto cell: row){
            cout<<cell<<" ";
        }
        cout<<endl;
    }
    return 0;
}