# Function to check if a number is composite
def is_composite(num):
    if num < 4:  # Composite numbers are 4 and above
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return True
    return False

# Function to print composite numbers in a given range
def print_composite_numbers(start, end):
    composite_numbers = [num for num in range(start, end + 1) if is_composite(num)]
    print("Composite numbers between", start, "and", end, ":", composite_numbers)
