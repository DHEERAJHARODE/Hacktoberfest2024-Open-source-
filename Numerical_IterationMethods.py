from sympy import *
from prettytable import PrettyTable
import math


def iterationmethodSingle(function, x, accuracy):
    
    def f(x):
        f = eval(function)
        return f

    i = None
    n = 0
    old_x = None

    tolerance = 0.5 / (10**(accuracy))
    print(f"The tolerance is {tolerance}.")

    table = PrettyTable(["No.", "x"])
    table.add_row([0, x])
    while true:
        i = f(x)
        old_x = x
        x = round(i, accuracy + 1)
        n += 1
        
        table.add_row([n, x])

        if(old_x == x):
            break

    print(table)
    print(f"The required root is {x} after {n} iterations.")
   




functionF = str(input("Enter the first function f(x, y) for x: "))
accuracy = int(input("Enter the accuracy of the decimal digits: ")) 
initial_x = float(input("Enter the initial approximation of x: "))

x = symbols('x')


derivativeF_wrt_x = str(diff(functionF, x)) # = ∂F/∂x

def F_x(x):
    F_x = eval(derivativeF_wrt_x)
    return F_x

a = F_x(initial_x)


if(abs(a)  < 1):
    iterationmethodSingle(str(functionF), initial_x, accuracy)
    
else:
    print(f"The given function f(x) is not convergent.")
