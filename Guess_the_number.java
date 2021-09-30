package com.apurba;

import java.util.Random;
import java.util.Scanner;

public class Guess_the_number
{
    public static void main(String[] args)
    {
        Random random = new Random();
        Scanner scanner = new Scanner(System.in);

        System.out.println("***Welcome to THE NUMBER GUESSING GAME***");
        System.out.println("Type 'V' for Very Easy\nType 'N' for Novice Easy\nType 'R' for Rookie Medium");
        System.out.println("---------------------");

        System.out.print("Select Game LEVEL : ");
        char choiceLevel = scanner.next().charAt(0);

        System.out.print("How many TIMES you want to Play the GAME : ");
        int userTurns = scanner.nextInt();

        int bound = 0;
        if (choiceLevel=='V'||choiceLevel=='v')
        {
            bound = 10;
            System.out.println("Choose a Number from 0 -- "+bound);
        }
        else if (choiceLevel=='N'||choiceLevel=='n')
        {
            bound = 25;
            System.out.println("Choose a Number from 0 -- "+bound);
        }
        else if (choiceLevel=='R'||choiceLevel=='r')
        {
            bound = 50;
            System.out.println("Choose a Number from 0 -- "+bound);
        }
        else
        {
            System.out.println("Enter a Valid choice Next time\nBye for Now");
            System.exit(0);
        }
        int randomNumber = random.nextInt(bound);
        int gameTurns;

        for (gameTurns = 0; gameTurns < userTurns; gameTurns++)
        {
            System.out.print("Guess the number : ");
            int userChoice = scanner.nextInt();

            if (userChoice == randomNumber)
            {
                System.out.println("!!!!You have WON the GAME!!!\n(:");
                System.out.println("You have GUESSED the number in "+gameTurns+" ATTEMPTS");
                break;
            }
            else if (userChoice > randomNumber && gameTurns != userTurns - 1)
            {
                System.out.println("Your Guess is HIGHER than the SECRET Number\nChoose a LOWER number...");
            }
            else if (userChoice < randomNumber && gameTurns != userTurns - 1)
            {
                System.out.println("Your Guess is LOWER than the SECRET Number\nChoose a HIGHER number...");
            }
            else
            {
                System.out.println("----You have LOSE the GAME---- \nWRONG choice");
                System.out.println("You took "+gameTurns+" attempts\nBut You LOSE...):");
                break;
            }
        }
        System.out.print("--- The NUMBER was = "+randomNumber+" ---");
    }
}