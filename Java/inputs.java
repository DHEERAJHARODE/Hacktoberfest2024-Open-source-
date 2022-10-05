package com.harsh;

import java.util.Scanner;

public class inputs {
    public static void main(String[] args) {
        System.out.print("Please enter an input:  ");
        Scanner input = new Scanner(System.in);
        int rollno = input.nextInt();
        System.out.println("Your roll no is "+ rollno);
    }
}
