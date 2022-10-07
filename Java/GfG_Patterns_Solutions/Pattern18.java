import java.util.Scanner;

public class Pattern18 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        printSquare(n);
    }
    static void printSquare(int n){
        for (int i = 1; i <= n; i++) {
            int a = (65 + n - 1);
            for (int j = 1; j <= i; j++) {
                System.out.print((char) a + " ");
                a--;
            }
            System.out.println();
        }
    }
}
