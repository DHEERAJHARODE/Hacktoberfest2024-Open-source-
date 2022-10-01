from colorama import Fore, Back, Style
from termcolor import colored
import random

suits = ["Spades", "Hearts", "Clubs", "Diamonds"]
suits_values = {"Spades":"\u2664", "Hearts":"\u2661", "Clubs": "\u2667", "Diamonds": "\u2662"}
ranks = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]
rank_values = {"A": 11, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "10":10, "J":10, "Q":10, "K":10}

class Card:
    def __init__(self, suit, rank, value):
        self.suit = suit
        self.rank = rank
        self.value = value


# Generate Deck
deck = []
for suit in suits:
    for rank in ranks:
        deck.append(Card(suits_values[suit], rank, rank_values[rank]))


# Function to print hands
def print_hands(cards, hidden):
    for card in cards:
        print(card.suit + " " + card.rank)
    if hidden == True:
        print("?")



# Blackjack Game
def blackjack(deck):
    global rank
    global suit
    global rank_values

    # Player and Dealer Hands
    player_hand = []
    dealer_hand = []

    # Player and Dealer Score
    player_score = 0
    dealer_score = 0

    # Initial dealing 
    while len(player_hand) < 2:

        # Randomly dealing player cards 
        player_card = random.choice(deck)
        player_hand.append(player_card)
        deck.remove(player_card)

        player_score += player_card.value

        # Both ace cards dealt 
        if len(player_hand) == 2:
            if(player_hand[0].value == 11 and player_hand[1].value == 11):
                player_hand[0].value = 1
                player_score -= 10

        print("Player Hand: ")
        print_hands(player_hand, False)
        print("Player Score: ")
        print(player_score)

        input()

        # Randomly dealing dealer cards
        dealer_card = random.choice(deck)
        dealer_hand.append(dealer_card)
        deck.remove(dealer_card)

        dealer_score += dealer_card.value

        print("Dealer hand: ")
        if len(dealer_hand) == 1:
            print_hands(dealer_hand, False)
            print("Dealer Score: ")
            print(dealer_score)
        else:
            print_hands(dealer_hand[:-1], True)    
            print("Dealer Score: ", dealer_score - dealer_hand[-1].value)

        if len(dealer_hand) == 2:
            if dealer_hand[0].value == 11 and dealer_hand[1].value == 11:
                dealer_hand[1].value = 1
                dealer_score -= 10

        print("-------------------------------------")
 
        input()

    if player_score == 21:
        print(colored("Player hits 21", "green"))
        print(colored("Player Wins", "green"))
        quit()

    # Stage 2
    while player_score < 21:
        choice = input(colored("Hit or Stand (H/S): ", "yellow"))

        if choice.upper() == 'H':

            # Deal a new card
            player_card = random.choice(deck)
            player_hand.append(player_card)
            deck.remove(player_card)

            player_score += player_card.value


            # Ace check 
            c = 0
            while player_score > 21 and c < len(player_hand):
                if(player_hand[c].value == 11):
                    player_hand[c].value = 1
                    player_score -= 10
                    c += 1

                else:
                    c += 1


            print("Player Hand: ")
            print_hands(player_hand, False)
            print("Player Score: ", player_score) 
            print()

            print("Dealer Hand: ")
            print_hands(dealer_hand[:-1], True)
            print("Dealer Score: ", dealer_score - dealer_hand[-1].value) 

            print("-------------------------------------")

        if choice.upper() == 'S':
            break

    # Stage 3
    print("Player Hand: ")
    print_hands(player_hand, False)
    print("Player Score: ", player_score) 
    print()
    
    print(colored("Dealer Reveals Hand", "yellow"))
    print("Dealer Hand: ")
    print_hands(dealer_hand, False)
    print("Dealer Score: ", dealer_score) 

    print("-------------------------------------")

    if player_score == 21:
        print(colored("Player hits 21", "green"))
        print(colored("Player Wins", "green"))
        quit()
 
    # Check player bust
    if player_score > 21:
        print(colored("Player Busted", "red"))
        quit()
 
    input() 

    # Managing Dealer Moves
    while dealer_score < 17:
        print(colored("Dealer Hits", "yellow"))

        dealer_card = random.choice(deck)
        dealer_hand.append(dealer_card)
        deck.remove(dealer_card)

        dealer_score += dealer_card.value

        # Ace check 
        c = 0
        while player_score > 21 and c < len(player_hand):
            if(player_hand[c].value == 11):
                player_hand[c].value = 1
                player_score -= 10
                c += 1
            else:
                c += 1

        print("Player Hand: ")
        print_hands(player_hand, False)
        print("Player Score: ", player_score) 
        print()

        print("Dealer Hand: ")
        print_hands(dealer_hand, False)
        print("Dealer Score: ", dealer_score) 

        print("-------------------------------------")

    # Final Score Check
    if dealer_score > 21:        
        print(colored("Dealer Busted", "red"))
        quit()  
 
    if dealer_score == 21:
        print(colored("Dealer hits 21", "green"))
        print(colored("Dealer Wins", "green"))
        quit()
 
    if dealer_score == player_score:
        print("Tie")
 
    elif player_score > dealer_score:
        print(colored("Player Wins", "green"))                 
 
    else:
        print(colored("Dealer Wins", "green"))   

blackjack(deck)
