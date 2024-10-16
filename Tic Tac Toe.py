# Constants for players and board
PLAYER_X = 'X'
PLAYER_O = 'O'
EMPTY = ' '

# Winning combinations (indices of the board that make a win)
WIN_COMBINATIONS = [
    [0, 1, 2],  # Top row
    [3, 4, 5],  # Middle row
    [6, 7, 8],  # Bottom row
    [0, 3, 6],  # Left column
    [1, 4, 7],  # Middle column
    [2, 5, 8],  # Right column
    [0, 4, 8],  # Diagonal
    [2, 4, 6]   # Diagonal
]

# Initialize board with empty spaces
def initialize_board():
    return [EMPTY] * 9

# Print the board in a 3x3 grid format
def print_board(board):
    print(board[0] + '|' + board[1] + '|' + board[2])
    print('-+-+-')
    print(board[3] + '|' + board[4] + '|' + board[5])
    print('-+-+-')
    print(board[6] + '|' + board[7] + '|' + board[8])

# Check if the player has won
def check_win(board, player):
    for combo in WIN_COMBINATIONS:
        if all(board[i] == player for i in combo):
            return True
    return False

# Check if the board is full (i.e., a tie)
def is_board_full(board):
    return EMPTY not in board

# Main game loop
def play_game():
    board = initialize_board()
    turn = PLAYER_X
    move_count = 0

    while True:
        print_board(board)
        move = input(f"It's your turn, {turn}. Move to which place (1-9)? ")

        # Validate the move input
        if not move.isdigit() or not (1 <= int(move) <= 9) or board[int(move) - 1] != EMPTY:
            print("Invalid move. Try again.")
            continue

        # Update board and move count
        board[int(move) - 1] = turn
        move_count += 1

        # Check for win condition
        if move_count >= 5 and check_win(board, turn):
            print_board(board)
            print(f"\nGame Over.\n**** {turn} won! ****")
            break

        # Check for tie
        if is_board_full(board):
            print_board(board)
            print("\nGame Over.\nIt's a Tie!")
            break

        # Switch turn
        turn = PLAYER_O if turn == PLAYER_X else PLAYER_X

    # Ask for a restart
    restart = input("Do you want to play again? (y/n): ").lower()
    if restart == 'y':
        play_game()

if __name__ == "__main__":
    play_game()
