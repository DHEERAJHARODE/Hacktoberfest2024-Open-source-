package com.harsh;

import java.util.Scanner;

public class max3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int c = input.nextInt();
        int d = input.nextInt();



        //By using logic
        int max = a;
        if (b>max){
            max = b;
        }if(c > max){
            max = c;
        }
        System.out.println(max);

        //By using inbuilt function
//        int max = Math.max(d,Math.max(c,Math.max(a,b)));
//        System.out.println(max);

    }
}

