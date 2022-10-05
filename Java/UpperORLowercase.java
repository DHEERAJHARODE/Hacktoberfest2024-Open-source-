package com.harsh;

import java.util.Scanner;

public class UpperORLowercase {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        char ch = in.next().trim().charAt(0);
        if(ch >= 'a' && ch <= 'z') {
            System.out.println("Lowercase");
        }else{
            System.out.println("Uppercase");
        }

    }
}
