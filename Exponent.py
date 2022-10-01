a = int(input("Enter the base : "))
b = int(input("Enter the power : "))

result = a

for i in range(b-1):
    result = result*a

print("Result is : ", result)
