import java.util.Scanner;
import java.math.*;

public class ArmstrongNumber {
    public static void main(String args[]) {
        System.out.println("Enter your number to check if it is a Armstrong Number or not: ");
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int test = x, sum = 0, i = 0;
        while (test > 0) {
            test /= 10;
            i++;

        }
        test = x;
        while (test > 0) {
            int rem = test % 10;
            sum += Math.pow(rem, i);
            test /= 10;

        }
        if (x == sum) {
            System.out.println(x + " is a armstrong number!!");
        } else {
            System.out.println(x + " is not a armstrong number!!");
        }

    }
}
