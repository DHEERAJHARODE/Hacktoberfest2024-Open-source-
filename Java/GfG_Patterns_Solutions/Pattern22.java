import java.util.Scanner;

public class Pattern22 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        printSquare(n);
    }
    static void printSquare(int n){
        int a = 2 * n - 1;
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= a; j++) {
                int min1 = i <= a-i ? i-1 : a-i;
                int min2 = j <= a-j ? j-1 : a-j;
                int min = Math.min(min1, min2);
                System.out.print(n-min + " ");
            }
            System.out.println();
        }
    }
}
