import java.util.*;

class FibonacciSeries {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a Limit : ");
        int n = sc.nextInt();
        int a = 0;
        int b = 1;
        int count = 2;

        while (count <= n) {
            int temp = b;
            b = b + a;
            a = temp;
            count++;
            System.out.println(b);
        }

        System.out.println(b);

    }
}

// 0 1 1 2 3 5 8 13 21....
