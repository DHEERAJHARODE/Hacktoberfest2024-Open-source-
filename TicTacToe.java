import java.util.Scanner;

public class TicTacToe {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        char[][] board = new char[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        char player = 'x';
        display(board);
        while(!won('x' , board) && !won('o' , board) && !gameOver(board)) {
            player = play(player, board);
        }
    }

    private static boolean gameOver(char[][] board) {
        for(char[] chAr : board){
            for(char ch : chAr){
                if(ch == ' '){
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean won(char player ,char[][] board) {
        //
        for (int i = 0; i < 3; i++) {
            if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
                return true;
            }
        }
        for (int i = 0; i < 3; i++) {
            if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
                return true;
            }
        }
        if(board[0][0] == player && board[1][1] == player && board[2][2] == player || board[2][0] == player && board[1][1] == player && board[0][2] == player){
            return true;
        }
        return false;
    }

    public static char play(char player, char[][] board){
        Scanner val = new Scanner(System.in);
        System.out.println("player " + player + ", Enter row and column : ");
        int row = val.nextInt();
        int col = val.nextInt();
        if(row > 2 || col > 2){
            System.out.println("invalid box");
        }else if(board[row][col] == ' ' ){
            board[row][col] = player;
            char played = player;
            if(player == 'x'){
                player = 'o';
            }else{
                player = 'x';
            }
            if(won(played,board)){
                System.out.println("Player " + player + " is WON !!!");
            }
            if(gameOver(board)){
                System.out.println("DRAW!! GAME OVER!!!");
            }
        }else{
            System.out.println("already filled box");
        }
        display(board);
        return player;
    }

    public static void display(char[][] board){
        for (int i = 0; i < 3; i++) {
            System.out.print("|");
            for (int j = 0; j < 3; j++) {
                System.out.print(" ");
                System.out.print(board[i][j]);
                System.out.print(" |");
            }
            System.out.println();
        }
    }
}
