package com.harsh;

import java.util.Scanner;

public class Reverse {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        int ans = 0;
        while (num>0){
          int rem = num % 10;
          ans = ans * 10 + rem;
          num /=10;
        }
        System.out.println(ans);


    }
}


