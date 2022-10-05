package com.harsh;

import java.util.Scanner;

public class prime {
    public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter a number");
    int n = in.nextInt();
    int count=0;
    //Logic
        for (int i = 1; i <=n; i++) {
            if (n % i == 0)
                count++;
        }
        if (count==2)
            System.out.println("It's a prime number\n");
        else
            System.out.println("It's not a prime number\n");
        //Note
        System.out.println("A number which has no positive divisors other than 1 " +
                "and itself is a PRIME NUMBER");
        }

    }
    //Using while loop
/*
        i=2;
        while(i<n){
        if(n%i==0){
        system.out.print("not prime");
        }
        else
        system.out.print("Prime")
        i++
        }
 */

    //#Optimized -->
//        if(n <= 1) {
//            System.out.println("Neither prime nor composite");
//            return;
//        }
//        int c = 2;
//        while (c * c <= n) {
//            if (n % c == 0) {
//                System.out.println("Not Prime");
//                return;
//            }
//            c = c + 1;
//            // c++;
//        }
//        if (c * c > n) {
//            System.out.println("Prime");
//        }

