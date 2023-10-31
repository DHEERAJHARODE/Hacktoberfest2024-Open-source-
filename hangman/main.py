import pygame
import math
import random

# Setup display
pygame.init()
WIDTH, HEIGHT = 1000, 700
win = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Hangman Game!")

# Fonts
LETTER_FONT = pygame.font.SysFont(None, 45)
WORD_FONT = pygame.font.SysFont(None, 60)
TITLE_FONT = pygame.font.SysFont(None, 80)

# Load images
images = [pygame.image.load(f'hangman{str(i)}.png') for i in range(7)]

# Button variables
RADIUS = 25
GAP = 10
letters = []
startx = round((WIDTH - (GAP + RADIUS * 2) * 13) / 2)
starty = 400
A = 65
for i in range(26):
    x = startx + GAP * 2 + ((RADIUS * 2 + GAP) * (i % 13))
    y = starty + ((i // 13) * (GAP + RADIUS * 2))
    letters.append([x, y, chr(A + i), True])

# Game variables
hangman_status = 0
word_list = ["PYTHON", "JAVA", "JAVASCRIPT", "HTML", "CSS"]
word = random.choice(word_list)
guessed = set()

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

def draw():
    win.fill(WHITE)

    # Draw title
    text = TITLE_FONT.render("HANGMAN GAME", 1, RED)
    win.blit(text, (WIDTH / 2 - text.get_width() / 2, 20))

    # Draw word
    display_word = ""
    for letter in word:
        if letter in guessed:
            display_word += letter + " "
        else:
            display_word += "_ "
    text = WORD_FONT.render(display_word, 1, BLACK)
    win.blit(text, (400, 200))

    # Draw buttons
    for letter in letters:
        x, y, ltr, visible = letter
        if visible:
            pygame.draw.circle(win, BLACK, (x, y), RADIUS, 3)
            text = LETTER_FONT.render(ltr, 1, BLACK)
            win.blit(text, (x - text.get_width() / 2, y - text.get_height() / 2))

    win.blit(images[hangman_status], (150, 100))
    pygame.display.update()

def display_message(message, color):
    pygame.time.delay(500)
    win.fill(color)
    text = WORD_FONT.render(message, 1, BLACK)
    win.blit(text, (WIDTH / 2 - text.get_width() / 2, HEIGHT / 2 - text.get_height() / 2))
    pygame.display.update()
    pygame.time.delay(3000)

def main():
    global hangman_status

    # Setup game loop
    FPS = 60
    clock = pygame.time.Clock()
    run = True

    while run:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                m_x, m_y = pygame.mouse.get_pos()
                for letter in letters:
                    x, y, ltr, visible = letter
                    if visible:
                        dis = math.sqrt((x - m_x) ** 2 + (y - m_y) ** 2)
                        if dis < RADIUS:
                            letter[3] = False
                            guessed.add(ltr)
                            if ltr not in word:
                                hangman_status += 1
        draw()

        if all(letter in guessed for letter in word):
            display_message("YOU WON!", GREEN)
            break

        if hangman_status == 6:
            display_message("YOU LOST! The word was: " + word, RED)
            break

    pygame.quit()

if __name__ == "__main__":
    main()

