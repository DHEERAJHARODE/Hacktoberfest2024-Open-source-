#Função recursiva de Fibonacci

def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

n = int(input("insira um numero: "))

print("Sequencia de Fibonacci: ", fibonacci(n))