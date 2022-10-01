import time
import random

start=time.time()

#Indices will be used for locating the spaces inside the board.
indicies=[int(i) for i in range(9)]
#Board will be used for updating/editing the values on the board.
board=[' ' for _ in range(9)]

#Board
def print_board(board):
	'''
	input: board

	Takes in board variable and prints the contents of it
	in the form of the tic tac toe board.

	returns: board with proper shape (visual purposes)
	'''
	
	print('-'*10,'BOARD','-'*10)
	print(*board[0:3],sep='|')
	print('-----  ')
	print(*board[3:6],sep='|')
	print('-----  ')
	print(*board[6:9],sep='|')
	print(' ')

def print_indices(indicies):
	'''
	input: indicies

	Takes in the indices list and displays the 
	positioning of the board w.r.t indices
	Used for making a move.

	output: tic tac toe board without values, with positioning values
	'''

	print(*indicies[0:3],sep='|')
	print('-----  ')
	print(*indicies[3:6],sep='|')
	print('-----  ')
	print(*indicies[6:9],sep='|')
	print(' ')

def is_space(board):
	'''
	input: board

	Checks if there is any empty space on the board, returns True if there is
	else False.

	output: True/False
	'''

	space=0

	if ' ' in board:
		space=True
	else:
		space=False
	return space

def check_winner(board):
	'''
	input: board

	checks if 3 consecutive (row/column/diagonal) values are equal.
	Since board is a list, its length is 9 , range from 0 to 8.

	0|1|2
	-----
	3|4|5
	-----
	6|7|8

	output: player/computer/none
	'''

	winner=None

	#Condition for rows (consecutive 3 vals 0/1/2 or 3/4/5 or 6/7/8)
	if board[0]==board[1]==board[2]=='O' or board[3]==board[4]==board[5]=='O' or board[6]==board[7]==board[8]=='O':
		winner='computer'
	if board[0]==board[1]==board[2]=='X' or board[3]==board[4]==board[5]=='X' or board[6]==board[7]==board[8]=='X':
		winner='player'
	
	#Condition for columns (0/3/6 or 1/4/7 or 2/5/8)
	if board[0]==board[3]==board[6]=='O' or board[1]==board[4]==board[7]=='O' or board[2]==board[5]==board[8]=='O':
		winner='computer'
	if board[0]==board[3]==board[6]=='X' or board[1]==board[4]==board[7]=='X' or board[2]==board[5]==board[8]=='X':
		winner='player'
	
	#Condition for diagonals (0/4/8 or 2/4/6)
	if board[0]==board[4]==board[8]=='O' or board[2]==board[4]==board[6]=='O':
		winner='computer'
	if board[0]==board[4]==board[8]=='X' or board[2]==board[4]==board[6]=='X':
		winner='player'
	
	#Check for draw (no empty space and no winners)
	if is_space(board)==False and winner==None:
		winner='draw'

	return winner

def check_winner_on_mark(board,mark):
	'''
	input: board and mark('X' or 'O')

	Checks if the mark is the winner.

	output: Returns true if mark is the winner, false otherwise.
	'''

	#Condition for rows (consecutive 3 vals 0/1/2 or 3/4/5 or 6/7/8)
	if board[0]==board[1]==board[2]==mark or board[3]==board[4]==board[5]==mark or board[6]==board[7]==board[8]==mark:
		return True
	
	#Condition for columns (0/3/6 or 1/4/7 or 2/5/8)
	if board[0]==board[3]==board[6]==mark or board[1]==board[4]==board[7]==mark or board[2]==board[5]==board[8]==mark:
		return True
	
	#Condition for diagonals (0/4/8 or 2/4/6)
	if board[0]==board[4]==board[8]==mark or board[2]==board[4]==board[6]==mark:
		return True
	
	return False

def make_move_player(board):
	'''
	input: indices, board

	Takes input from user (0-8 or 'board') , enters the value 'X' on the chosen position, 
	if position is preoccupied then asks to enter a different position, if user enters 'board'
	then print the numerical positions of the board(function->print_indicies)

	output: board list is updated with new values.
	'''

	your_move=input("Enter Move(type 'board' to see index):")

	#If 'board' is the input.
	if your_move.lower().strip()=='board':
		print('-'*10,'INDICES','-'*10)
		print_indices(indicies)
		#Ask to make move again after displaying index.
		make_move_player(board)
	else:
		your_move=int(your_move)
		#Checking if chosen position is empty, if it is
		#replacing empty string with 'X'.
		if board[your_move]==' ':
			board[your_move]='X'
		else:
			print('Choose empty space!')
			#If position isn't empty, run the function again.
			make_move_player(board)

def random_move_computer(indicies,board):
	'''
	input: board

	Randomly selects a position and if it is empty, substitutes it for 'O'.

	output: board with updated values.
	'''

	move=random.choice(indicies)
	if board[move]==' ':
		board[move]='O'
	else:
		random_move_computer(indicies,board)

def smart_move(board):
	'''
	input: board

	Default best score is -1000 and best move is initialzed to 0. This function checks for every empty space on
	the board and changes it to 'O' then calls the minimax function, if the score is greater than the best score, 
	then it changes the best score to the score obtained and the empty space to 'O'.

	output: updates board list with new values
	'''
	best_score=-1000
	best_move=0
	#Iterating over every possible space on the board.
	for i in indicies:
		#Initialising an empty space to 'O' and calling the minimax function.
		#isMaximising parameter is set to False because the goal is to minimize the loss of 'O'.
		if board[i]==' ':
			board[i]='O'
			score=minimax(indicies,board,False)
			#Returning the space to its original value
			board[i]=' '
			#If score is better than the best score, replace it and choose this location as the best possible move.
			if score>best_score:
				best_score=score
				best_move=i

	board[best_move]='O'


def minimax(indicies,board,isMaximizing):
	'''
	input: indices , board and Boolean value(True/False) for isMaximizing

	In this function the if loop (line 219) and else loop play against each other again and again
	and play out each possible state and then check who is the winner , value of score changes and 
	this repeats until bot('O') wins.

	output: returns best score 

	'''
	bot='O'
	player='X'
	#Returning 100 if the computer 'O' wins.
	if check_winner_on_mark(board,bot):
		return 100
	#Returning -100 if the player 'X' wins.
	elif check_winner_on_mark(board,player):
		return -100
	#Returning 0 if theres a draw.
	elif check_winner(board)=='draw':
		return 0

	#isMaximizing -> True , Computer or 'O' plays.
	if isMaximizing:
		best_score=-1000
		for i in indicies:
			if board[i]==' ':
				board[i]='O'
				score=minimax(indicies,board,False)
				board[i]=' '

				if score> best_score:
					best_score=score
		
		return best_score

	#isMaximizing -> False, Player or 'X' plays.
	else:
		best_score=800
		for i in indicies:
			if board[i]==' ':
				board[i]='X'
				score=minimax(indicies,board,True)
				board[i]=' '

				if score<best_score:
					best_score=score

		return best_score


def easy_game():
	'''
	Easy Game Mode: Computer makes random moves as 'O'.
	'''
	#Initialize winner to none.
	winner=None
	#Play the game until theres a winner.
	while winner==None:
		print_board(board)
		make_move_player(board)
		#Checking for a winner.
		winner=check_winner(board)
		
		#Checking if theres a draw.
		if winner=='draw' or winner=='player' or winner=='computer':
			break
		
		random_move_computer(indicies,board)
		#Checking for a winner.
		winner=check_winner(board)
		
		#Checking if theres a draw.
		if winner=='draw' or winner=='player' or winner=='computer':
			break

		print('='*50)
	print('Winner is {}'.format(check_winner(board)))
	print_board(board)


def hard_game():
	'''
	Hard Game Mode: Computer makes moves as 'O' based on the scores from the minimax algorithm.
	'''
	#Initialize winner to none.
	winner=None
	#Play the game until theres a winner.
	while winner==None:
		print_board(board)
		make_move_player(board)
		#Checking for a winner.
		winner=check_winner(board)
		
		#Checking for draw.
		if winner=='draw' or winner=='player' or winner=='computer':
			break
		
		smart_move(board)
		#Checking for a winner.
		winner=check_winner(board)
		
		#Checking for draw.
		if winner=='draw' or winner=='player' or winner=='computer':
			break

		print('='*50)
	print('Winner is {}'.format(check_winner(board)))
	print_board(board)


if __name__=='__main__':
	difficulty=input("Enter Difficulty (Easy or Hard):").lower().strip()

	if difficulty=='easy':
		easy_game()
	if difficulty=='hard':
		hard_game()
	else:
		print("Enter 'Easy' or 'Hard'")

end=time.time()
print('Game Lasted for {} seconds.'.format(end-start))
