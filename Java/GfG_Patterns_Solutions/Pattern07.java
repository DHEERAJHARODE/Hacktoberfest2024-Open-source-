import java.util.Scanner;

public class Pattern07 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        printSquare(n);
    }
    static void printSquare(int n){
        int space = n-1;
        int star = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= space ; j++) {
                System.out.print(" ");
            }
            for (int j = 1; j <= star; j++) {
                System.out.print("*");
            }
            space--;
            star += 2;
            System.out.println();
        }
    }
}
