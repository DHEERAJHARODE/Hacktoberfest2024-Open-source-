package com.harsh;

import java.util.Scanner;

public class Switch_case {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
//        String fruit = in.next();

//        switch (fruit){
//            case "Mango":
//                System.out.println("King of fruits");
//                break;
//            case "Apple":
//                System.out.println("Keeps doctor away");
//                break;
//            case "Orange":
//                System.out.println("Round fruit");
//                break;
//            default:
//                System.out.println("Please enter a valid fruit");
//
//        }
//        int day = in.nextInt();
//        switch (day) {
//            case 1, 2, 3, 4, 5 -> System.out.println("Weekdays");
//            case 6, 7 -> System.out.println("Weekends");
//        }
        int EmpId = in.nextInt();
        String department = in.next();

        switch (EmpId){
            case 1:
                System.out.println("Harry");
                break;
            case 2:
                System.out.println("Potter");
                break;
            case 3:
                switch (department) {
                    case "IT" -> System.out.println("IT department");
                    case "Management" -> System.out.println("Management");
                }break;
        }







    }
}