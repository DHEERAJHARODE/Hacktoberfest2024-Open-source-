#Program to solve quadratic equation

import math
A,B,C = map(int,input("Enter Value For A, B and C---> ").split())
d = B ** 2 - 4 * A * C
R1 = ((- B - math.sqrt(d)) / 2 * A)
R2 = ((- B + math.sqrt(d)) / 2 * A)
print("These are two possible Roots: {0} and {1}".format(R1, R2))
