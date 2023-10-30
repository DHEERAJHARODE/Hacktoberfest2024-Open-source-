from turtle import Turtle,Screen
import random

is_race=False
screen=Screen()
screen.setup(width=500,height=400)
y_axis=-100
colors=["red","blue","violet","indigo","green","yellow",'orange']
all_turtles=[]
user_color_1=screen.textinput(title="Player 1 Bet", prompt="Choose your Color")
user_color_2=screen.textinput(title="Player 2 Bet", prompt="Choose your Color")

jimmy=Turtle()
jimmy.penup()
jimmy.goto(230, -200)
jimmy.left(90)
jimmy.pendown()
jimmy.forward(400)
jimmy.hideturtle()

for i in range(0,7):
    timmy_1 = Turtle(shape="turtle")
    timmy_1.color(colors[i])
    timmy_1.penup()
    timmy_1.goto(x=-230, y=y_axis)
    y_axis+=30
    all_turtles.append(timmy_1)

if user_color_1:
    is_race=True

while is_race:
    for i in all_turtles:

        if i.xcor() > 230:
            is_race = False
            if user_color_1 == i.pencolor():
                print(f"Player 1 Won {user_color_1} is the winner.")
            elif user_color_2 ==i.pencolor():
                print(f"Player 2 Won the game...{user_color_2} is the winner.")

            else:
                print(f"Oops!!Both of you  lost the game. {i.pencolor()} is the winner.")

            break

        n = random.randint(0, 10)
        i.forward(n)







screen.exitonclick()
