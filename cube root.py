# write a code to find cube root of a number
# using guess and check method
# x is the number whose cube root is to be found
# epsilon is the error allowed
# increment is the value by which guess is incremented
# guess is the number whose cube is to be checked
# num_guesses is the number of guesses made
# if the cube of guess is close to x, then guess is the cube root of x
# else guess is incremented by increment and checked again
# if guess reaches x, then cube root of x is not possible
# if guess reaches x + increment, then increment is reduced
# and guess is set to x again
# this is done until guess is close to x
# if guess is close to x, then guess is the cube root of x
# else cube root of x is not possible
# code


def guessAndCheck(x):
    epsilon = 0.01
    increment = 0.0001
    guess = 0.0
    num_guesses = 0
    while abs(guess**3 - x) >= epsilon and guess <= x:
        guess += increment
        num_guesses += 1
    if abs(guess**3 - x) >= epsilon:
        print("Failed on cube root of", x)
    else:
        print(guess, "is close to the cube root of", x)
    
    print("Number of guesses:", num_guesses)

def powerMethod(x):
    return x**(1/3)


x = int(input("Enter a number: "))

print("\n")
print("Using guess and check method:")
guessAndCheck(x)

print("Using power method:")
print(powerMethod(x))

