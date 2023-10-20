import turtle

BODY_COLOR =  'skyblue'
BODY_SHADOW = ''
GLASS_COLOR = '#9acedc'
GLASS_SHADOW = ''

s = turtle.getscreen()
t = turtle.Turtle()

# it can move forward backward left right
def body():
    """ draws the body """
    t.pensize(20)
    #t.speed(15)

    t.fillcolor(BODY_COLOR)
    t.begin_fill()

    # right side
    t.right(90)
