/*#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>*/
#include <bits/stdc++.h>
using namespace std;
class Casino
{
  public:  
  void sdisplay ()
  {
    cout << "\n\n\t\t>>>Welcome to SLOT MACHINE!!!<<<\n" << endl;
  }
  void rdisplay ()
  {
    cout << "\n\n\t\t>>>Welcome to ROULETTE!!!<<<\n" << endl;
  }
  void bdisplay ()
  {
    cout << "\n\n\t\t>>>Welcome to BLACKJACK!!!<<<\n" << endl;  
  }
  void rules()
  {
    cout << "\n\t\t======ROULETTE RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. If the number you bet gets selected then you get 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
  }
  void srules()
  {
    cout<<"\t\t======SLOT MACHINE RULES!======\n";
    cout<<"\t1. Press Y to pull the lever.\n";
    cout<<"\t2. If all slots are equal you win a JACKPOT.\n";
    cout<<"\t3. If slots are different you lose the amount you bet.\n\n";
  }
  void brules()
   {
    cout<<"\t\t======BLACKJACK RULES!======\n";
    cout<<"\t1. You will be distributed two cards.\n";
    cout<<"\t2. If you get a face card and an Ace, then its a BLACKJACK.\n";
    cout<<"\t3. If the total of your cards is more than that of the dealer you win else you lose.\n\n";
  }
};  
int main()
{
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int option;
    int guess;
    int dice; // stores the random number
    char choice;
    char c;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t\t========|||WELCOME TO 'LOTUS' CASINO|||=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\nEnter the money you want to spend in our casino : $";
    cin >> balance;
    do
    {
// Get player's betting balance
        GAMEsSelection:
        cout<<"\n\nWhere do you want to try your luck? \n\n1.Roulette \n2.Slot Machine \n3.Blackjack \n\nchoose 1 or 2 or 3 : ";
        cin>> option;
// ROULETTE.
        if(option == 1)
        {
        do
        {
           Casino C;
           C.rdisplay();
           C.rules(); 
            cout << "\n\nYour current balance is $ " << balance << "\n";
            cout << "Hey, " << playerName<<", enter amount to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                       <<"\nRe-enter balance\n ";
        }while(bettingAmount > balance);
// Get player's numbers
        do
        {
            cout << "\nGuess any betting number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        if(dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have balance of $ " << balance << "\n";
        if(balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
        }
// SLOT MACHINE.
        else if(option == 2)
        {
          Casino C;
          C.sdisplay ();
          C.srules();
           do
           {
             cout << "\n\nYour current balance is $ " << balance << "\n";
             cout << "Hey, " << playerName<<", enter amount to bet : $";
             cin >> bettingAmount;
              if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                     <<"\nRe-enter balance\n ";
           }while(bettingAmount > balance);
          cout << "\nPress Y to pull the lever or press N to go back to GAMEs selection" << endl;
          cin >> c;
           if (c == 'Y' || c == 'y')
           {
	         srand (time (0));
	         int one = (rand()%7) + 1;
         	 int two = (rand()%7) + 1;
	         int three = (rand()%7) + 1;
	         cout<<"\n\t\t\t\t===>"<<one<<three<<two<<"<===\n"<<endl;
	         if ((one == two) && (two == three))
	         {
	             cout << "YOU ARE LUCKY!!! \n" << "YOU WIN A JACKPOT OF " << (bettingAmount*100)<< "!!!" << endl;
	             balance = balance + bettingAmount * 100;
	         }
	         else
	         {
	            cout << "\nOops, better luck next time !! You lost $ "<< bettingAmount <<endl;
                balance = balance - bettingAmount;
                cout << "\n"<<playerName<<", You have balance of $ " << balance << "\n";
	         }
            }
            else if (c == 'N' || c == 'n')
            {
	         goto  GAMEsSelection;
            }
            else
            {
       	    cout << "You pressed the wrong key!!!" << endl;
            } 
            if(balance == 0)
            {
            cout << "You have no money to play ";
            break;
            }
            cout << "\n\n-->Do you want to play again (y/n)? ";
            cin >> choice;
        }
// BLACKJACK
        else if(option == 3)
        {
            Casino C;
            C.bdisplay ();
            C.brules();
            srand(time(0));

         	do
           {
             cout << "\n\nYour current balance is $ " << balance << "\n";
             cout << "Hey, " << playerName<<", enter amount to bet : $";
             cin >> bettingAmount;
              if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                     <<"\nRe-enter balance\n ";
           }while(bettingAmount > balance);	

	        int dealer_card1 = rand() % 13 + 1;  //dealer card 1 
        	int dealer_card2 = rand() % 13 + 1;	 //dealer card 2
        	int player_card1 = rand() % 13 + 1;	 //player card 1
	        int player_card2 = rand() % 13 + 1;  //player card 2

         	cout << "\n" << "\tThe dealer has "; 

	        switch (dealer_card1)
            {
		        case 1: cout << "Ace and "; 
		     	break;
		        case 11: cout << "Jack and "; 
		    	break;
	        	case 12: cout << "Queen and ";
		    	break;
		        case 13: cout << "King and "; 
		    	break;
		        default: cout << dealer_card1 << " and ";
		     	break;
	         }
	switch (dealer_card2) 
	{
		case 1: cout << "Ace"; 
			break;
		case 11: cout << "Jack"; 
			break;
		case 12: cout << "Queen"; 
			break;
		case 13: cout << "King"; 
			break;
		default: cout << dealer_card2;
			break;
	}
	cout << "\n" << "\n" << "\tYou have ";
	switch (player_card1)
	{
		case 1: cout << "Ace and "; 
		break;
		case 11: cout << "Jack and "; 
			break;
		case 12: cout << "Queen and "; 
			break;
		case 13: cout << "King and "; 
			break;
		default: cout << player_card1 << " and "; 
			break;
	}
	switch (player_card2)
	{
		case 1: cout << "Ace"; 
			break;
		case 11: cout << "Jack"; 
			break;
		case 12: cout << "Queen"; 
			break;
		case 13: cout << "King"; 
			break;
		default: cout << player_card2;
			break;
	}
	cout << "\n";

	int dealer_total = dealer_card1 + dealer_card2;
	int player_total = player_card1 + player_card2;

	if ((player_card1 == 1) && (player_card2 == 10|11|12|13))
	{
	    cout << "\n Blackjack! You Win $ " << bettingAmount*1.5 << "!!" << endl;
	     balance = balance + bettingAmount*1.5;
	}
	else if ((player_card2 == 1) && (player_card1 == 10|11|12|13))
	{
	   	cout << "\nBlackjack! You Win $ " << bettingAmount*1.5 << "!!" << endl;
	   	 balance = balance + bettingAmount *1.5;
	}
	else if (player_total > dealer_total)
	{
		cout << "\n" << "You win a majority. $" << bettingAmount << "!!" << endl;
		 balance = balance + bettingAmount;
	}
	else 
		cout << "\n" << "You lose" << endl;
		 balance = balance - bettingAmount;
		 cout << "\n"<<playerName<<", You have balance of $ " << balance << "\n";
	if(balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
        }
        else
        {
            cout<<"Please choose from given option."<< endl;
        }
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}

