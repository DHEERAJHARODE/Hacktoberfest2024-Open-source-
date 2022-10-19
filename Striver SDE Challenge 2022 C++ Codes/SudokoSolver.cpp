bool isProbable(int row, int col, char c, vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][col]==c) return false;
            if(board[row][i]==c) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c) return false;
        }
        return true;
    }
    bool ss(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isProbable(i,j,c,board)){
                        board[i][j]=c;
                        if(ss(board)) return true; //calling recn
                        else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        ss(board);
    }