import matplotlib.pyplot as plt

plt.title("Bresenham Circle Algorithm")
plt.xlabel("X Axis")
plt.ylabel("Y Axis")

def draw_circle(xc, yc, r):
    x=0
    y=r
    d=3- 2*r

    xcoordinates = []
    ycoordinates = []

    while x <= y:
        xcoordinates.extend([xc+x, xc-x, xc+x, xc-x, xc+y, xc-y, xc+y, xc-y])
        ycoordinates.extend([yc+y, yc+y, yc-y, yc-y, yc+x, yc+x, yc-x, yc-x])

        if (d<0):
            d = d+(4*x)+ 6
        else:
            d = d+ 4*(x-y)+10
            y-= 1
        x+=1

    plt.scatter(xcoordinates, ycoordinates, marker='.')
    plt.gca().set_aspect('equal', adjustable='box')
    plt.show()

def main():
    xc = int(input("Enter the center point of x:"))
    yc = int(input("Enter the center point of y:"))
    r = int(input("Enter the radius:"))

    draw_circle(xc, yc, r)

main()
