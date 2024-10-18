import math
import os
import random
import re
import sys

# Function to perform the circular array rotation
def circularArrayRotation(a, k, queries):
    # Find the effective number of rotations
    x = k % len(a)
    
    # Rotate the array: split it into two parts and re-arrange
    a = a[-x:] + a[:-x]
    
    # Create a result list to store the elements for the given queries
    res = []
    for q in queries:
        res.append(a[q])
    
    # Return the result
    return res

# Main function to handle input and output
if __name__ == '__main__':
    # Read input from stdin
    first_multiple_input = input().split()
    n = int(first_multiple_input[0])  # Number of elements in the array
    k = int(first_multiple_input[1])  # Number of rotations
    q = int(first_multiple_input[2])  # Number of queries

    # Read the array 'a'
    a = list(map(int, input().rstrip().split()))

    # Read the queries
    queries = []
    for _ in range(q):
        queries_item = int(input())
        queries.append(queries_item)

    # Call the function with the array, number of rotations, and queries
    result = circularArrayRotation(a, k, queries)

    # Output the result for each query
    for res in result:
        print(res)
