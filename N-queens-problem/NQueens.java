public class NQueens {
    public static void main(String[] args) {
        int n = 8; // Change this to the desired board size
        solveNQueens(n);
    }

    public static void solveNQueens(int n) {
        int[] queens = new int[n];
        placeQueens(queens, 0, n);
    }

    public static void placeQueens(int[] queens, int row, int n) {
        if (row == n) {
            printQueens(queens);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(queens, row, col)) {
                queens[row] = col;
                placeQueens(queens, row + 1, n);
            }
        }
    }

    public static boolean isSafe(int[] queens, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == col || queens[i] - i == col - row || queens[i] + i == col + row) {
                return false;
            }
        }
        return true;
    }

    public static void printQueens(int[] queens) {
        int n = queens.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (queens[i] == j) {
                    System.out.print("Q ");
                } else {
                    System.out.print(". ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }
}
