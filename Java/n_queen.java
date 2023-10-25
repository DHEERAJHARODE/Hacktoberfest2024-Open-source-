import java.util.*;
public class n_queen {
    
    //this functio checks if the cell in which queen is to placed is safe or not.
    public static boolean isSafe(int row, int col, char[][] board) {
        
        //checking horizontally, if any other queen has been already placed in that row.
        for(int j=0; j<board.length; j++) {
            if(board[row][j] == 'Q') {
                return false;
            }
        }
      
        //checking vertically, if any other queen has been already placed in that column.
        for(int i=0; i<board.length; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
      
        //checking if queen has been already placed in that upper left diagonal
        int r = row;
        for(int c=col; c>=0 && r>=0; c--, r--) {
            if(board[r][c] == 'Q') {
                return false;
            }
        }
      
        //checking if queen has been already placed in that upper right diagonal
        r = row;
        for(int c=col; c<board.length && r>=0; r--, c++) {
            if(board[r][c] == 'Q') {
                return false;
            }
        }
      
       //checking if queen has been already placed in that lower left diagonal
       r = row;
       for(int c=col; c>=0 && r<board.length; r++, c--) {
           if(board[r][c] == 'Q') {
               return false;
           }
       }
      
        //checking if queen has been already placed in that lower right diagonal
        for(int c=col; c<board.length && r<board.length; c++, r++) {
            if(board[r][c] == 'Q') {
                return false;
            }
        }
      
        return true;
    }
    
    // to save each arrangement present in board of characters, we first convert it as board of string and then save the list in all boards (which is list of lists of string)
    public static void saveBoard(char[][] board, List<List<String>> allBoards) {
        
        String row = "";
        
        // this will contain the arrangement of board as string
        List<String> newBoard = new ArrayList<>();
        
        //traversing through the board of characters and saving each row as string in newBoard
        for(int i=0; i<board.length; i++) {
            row = "";
            for(int j=0; j<board[0].length; j++) {
                if(board[i][j] == 'Q')
                    row += 'Q';
                else
                    row += '.';
            }
            newBoard.add(row);
        }
        
        // adding the list "new board" to list of lists of string called "allBoards"
        allBoards.add(newBoard);
    }
    
    //recursive function that explore possible moves to place a queen column by column
    public static void solve(char[][] board, List<List<String>> allBoards, int col) {
        
        // if column length  becomes equal to board.length, that implies all the columns have been explored and function solve is ready with its solution.
        if(col == board.length) {
            
            // when we have one of the ways to put queens, we save it as a list called "board" in list of lists "allboards" that contains all the possible solutions.
            saveBoard(board, allBoards);
            return;
        }
        
        // here we move column by column to place each queen in each column
        for(int row=0; row<board.length; row++) {
            
            // if the queen is safe to be put in the cell, we put 'Q' in that cell to know that queen has been placed
            if(isSafe(row, col, board)) {
                board[row][col] = 'Q';
                
                //we again call the solve function by incrementing the column by 1.
                solve(board, allBoards, col+1);
                
                // while backtracking, we put '.' in each cell showing that no queen has been placed there as in to again, to explore other solution or moves we need a clear board.
                board[row][col] = '.';
            }
        }
    }
    
    public static void solution(int n) {
        
        //all boards will contain  lists that are the possible solutions.
        List<List<String>> allBoards = new ArrayList<>();
        
        // each board would be of character so that we can put 'Q' to refer to queen placement and '.' to refer that no queen is placed there.
        char[][] board = new char[n][n];
        
        // calling the solve function to begin finding the possible arrangements
        solve(board, allBoards, 0);
        
        //printing the list of all solutions.
        for(List<String> aboard : allBoards){
            for(int i=0; i < aboard.size(); i++){
                System.out.println(aboard.get(i));
            }
            System.out.println();
        }
        

    }
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in); //System.in is a standard input stream.
        System.out.println("Enter board size")
        int size = sc.nextInt();;
        solution(size);
    }
}