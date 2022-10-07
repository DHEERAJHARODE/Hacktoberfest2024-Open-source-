import java.util.Scanner;

public class Pattern06 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        printSquare(n);
    }
    static void printSquare(int n){
        for (int i = 1; i <= n; i++) {
            int a=1;
            for (int j = n; j >= i; j--) {
                System.out.print(a + " ");
                a++;
            }
            System.out.println();
        }
    }
}
