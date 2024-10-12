public class nqueens {
    public static boolean issafe(char board[][],int row,int col)
    {//is it safe to place queen 
        //return true if it is safe 
        //vertically up //col will be same 
        
        for(int i = row-1,j=col;i>=0;--i)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        //diag left up//col will decrease and row will also decrease
        for(int i = row-1,j=col-1;i>=0&&j>=0;--i,--j)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        //diagonally right up // col will increase and row will decrease
        for(int i = row-1,j=col+1;i>=0&&j<board.length;--i,++j)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
    public static void nqueens1(char board[][],int row)
    {
        //base
        if(row==board.length)
        {
            printBoard(board);
            return;
        }
        //column loop
        for(int j=0;j<board.length;++j)
        {
            if(issafe(board, row,j))
           {board[row][j] = 'Q';//putting queen
           nqueens1(board, row+1);//fxn call for next row
           board[row][j]='X';//removing queen//backtracking
           }
        }
    }
    public static void printBoard(char board[][])
    {
        System.out.println("-------CHESS BOARD--------");
        for(int i=0;i<board.length;++i)
        {
            for(int j=0;j<board.length;++j)
            {
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int n = 4;
        char board[][]= new char[n][n];
        for(int i=0;i<n;++i)
        {
            for(int j =0;j<n;++j)
            {
                board[i][j] = 'X';
            }
        }
        nqueens1(board,0);
        
    }
}
