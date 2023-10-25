import pygame
import random

from pygame import mixer # for music

# Initilaze the pygame
pygame.init()

# creating the screen
screen = pygame.display.set_mode((800, 600))

# Background
background = pygame.image.load("background.png")

# Back ground music
mixer.music.load('background.wav')
mixer.music.play(-1)

# bullet sound
bullet_sound = mixer.Sound('laser.wav')

# collision sound
collision_sound = mixer.Sound('explosion.wav')

# set title to our game window
pygame.display.set_caption("Space Invaders") # set caption

# set logo to our game window
icon = pygame.image.load('ufo.png') # load image
pygame.display.set_icon(icon) # set image

# load our space ship  (player)

player_img = pygame.image.load("player.png")
player_x = 370
player_y = 480
player_xchange = 0
# load our eneimes
enemy_img = []
enemy_x = [] # list is to create multiple enimes
enemy_y = []
enemy_xchange = []
enemy_ychange = []

no_of_enemies = 6

for i in range(no_of_enemies):
    enemy_img.append(pygame.image.load("enemy.png"))
    enemy_x.append(random.randint(0, 735))
    enemy_y.append(random.randint(50, 150))
    enemy_xchange.append(2)
    enemy_ychange.append(40)

# load our bullet
bullet_img = pygame.image.load("bullet.png")
bullet_x =  0
bullet_y = 480
bullet_xchange = 0
bullet_ychange = 5
bullet_state = "ready"
# bullet has 2 states - ready and fire
# ready - we cant  see the bullet
# fire - the bullet is fired and can be seen

# to keep track of the score
score = 0

# font to add text on screen
font = pygame.font.Font('freesansbold.ttf', 32)

text_x = 10
text_y = 10

# game over text
over_font = pygame.font.Font('freesansbold.ttf', 64)


def show_score(x, y):
    ''' display score on screen '''
    s = font.render("SCORE :"  + str(score), True, (255, 255, 255))
    screen.blit(s, (x, y))

def game_over_text():
    over_text = over_font.render("GAME OVER :(",  True, (255, 255, 255))
    screen.blit(over_text, (230, 250))

def player(x, y):
    '''draw player img on screen based on x and y co-ordinates'''
    screen.blit(player_img, (x, y))

def enemy(x, y, i):
    ''' draw enemy img on screen based on x and y co-ordinates '''
    screen.blit(enemy_img[i], (x, y))


def fire_bullet(x, y):
    ''' fires a bullet '''
    global bullet_state
    bullet_state = "fire"
    screen.blit(bullet_img, (x + 16, y + 10))

def is_collision(ex, ey, bx, by):
    ''' checks if bullet and enemy coillides'''
    # if dis bw the bullet and enemy is less than 27 then they collide and enemy is destroyed
    return ((ex - bx) ** 2 + (ey - by) ** 2 ) ** 0.5 < 27

# Game loop
running = True # game runs until running becomes False

while running:
    # fill screen with colours
    screen.fill((0, 0, 0)) #- screen colours ( R, G, B)
    # add background image
    screen.blit(background, (0, 0))
    
    # checks all the events
    for event in pygame.event.get():
        #checks weither the cross button has been pressed
        if event.type == pygame.QUIT:
            running = False
            # quits the game

        # if key stroke is pressed - check direction and move in that direction

        if event.type == pygame.KEYDOWN: # checks if pressing any botton
            if event.key == pygame.K_LEFT: # is it left
                player_xchange = -3
            if event.key == pygame.K_RIGHT: # is it right
                player_xchange = 3
            if event.key == pygame.K_SPACE:
                bullet_sound.play()
                bullet_x = player_x
                fire_bullet(bullet_x, bullet_y)
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                player_xchange = 0
            
    # check whether the spaceship doesnot go out of the window
    
    if player_x <= 0: 
        player_x = 0
    elif player_x >= 736:
        player_x = 736
        

    
    for i in range(no_of_enemies):

        #game over - enemy reaches dowm we gonna end the game
        if enemy_y[i] > 440:
            for j in range(no_of_enemies):
                enemy_y[j] = 2000 # move all enemies out of the screen

            game_over_text()
            break
        
        # enemy movement
        enemy_x[i] += enemy_xchange[i]
        
        if enemy_x[i] <= 0: 
           enemy_xchange[i] = 1
           enemy_y[i] += enemy_ychange[i] # if enemy hits the side of window it moves down
        elif enemy_x[i] >= 736:
           enemy_xchange[i] = -1  
           enemy_y[i] += enemy_ychange[i] # if enemy hits the side of window it moves down
    
        # collision
        collision = is_collision(enemy_x[i], enemy_y[i], bullet_x, bullet_y)
        if collision:
          collision_sound.play()
          bullet_y = 480
          bullet_state = "start"
          score += 1
          #print(score)
          enemy_x[i] = random.randint(0, 735)
          enemy_y[i] = random.randint(50, 150)

          if no_of_enemies < 15:
              no_of_enemies += 1

              enemy_img.append(pygame.image.load("enemy.png"))
              enemy_x.append(random.randint(0, 735))
              enemy_y.append(random.randint(50, 150))
              enemy_xchange.append(2)
              enemy_ychange.append(40)
              
              enemy(enemy_x[i + 1], enemy_y[i + 1], i + 1)
              
          

        enemy(enemy_x[i], enemy_y[i], i)
        




    # bullet movement
    if bullet_y <= 0:
        bullet_y = 480
        bullet_state = "start"
    if bullet_state is "fire":
        fire_bullet(bullet_x, bullet_y)
        bullet_y -= bullet_ychange
    
    player_x += player_xchange
    
    # call player to introduce player into screen
    player(player_x, player_y)

    show_score(text_x, text_y)
    #enemy(enemy_x, enemy_y)

    # update screen
    pygame.display.update()

    


    
pygame.quit()
