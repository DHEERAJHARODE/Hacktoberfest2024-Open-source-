#include<bits/stdc++.h>
using namespace std;

int arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};
bool backTracking(int row, int colum, int index, vector<vector<int>>&visits, vector<vector<char>>& board, string&word){

    bool ans = false;

    if(index == word.length()){
        ans = true;
    }

    else{
        visits[row][colum] = 1;
        int i, auxRow, auxColum;

        for(i = 0; i<4 && !ans; i++){

            auxRow = row + arrRow[i];
            auxColum = colum + arrColum[i];

            if(auxRow != -1 && auxColum != -1 && auxRow != board.size() && auxColum != board[0].size() && !visits[auxRow][auxColum] && board[auxRow][auxColum] == word[index]){
                ans = backTracking(auxRow, auxColum, index+1, visits, board, word);
            }
        }
        visits[row][colum] = 0;
    }

    return ans;
}

bool exist(vector<vector<char>>& board, string word) {
        
    int i, j;
    bool ans = false;
    vector<vector<int>>visits(board.size(), vector<int>(board[0].size(), 0));

    for(i = 0; i<board.size() && !ans; i++){
        for(j = 0; j<board[0].size() && !ans; j++){
            if(board[i][j] == word[0]){
                ans = backTracking(i, j, 1, visits, board, word);
            }
        }
    }

    return ans;
}


int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << exist(board, word) << endl;
    return 0;
}