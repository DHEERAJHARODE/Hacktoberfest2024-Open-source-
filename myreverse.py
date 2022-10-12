#!/usr/bin/env python3

def reverseitbaby(x):
    return x[::-1]

inputstring = input("Enter a string, please.: ")

reversedstring = reverseitbaby(inputstring)

print("Reversed: " + reversedstring)
