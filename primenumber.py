def is_prime(n, i=2):
    if n<=2:
        return True if n == 2 else False
    if n%i == 0:
        return False
    if i*i<n:
        return True
    return is_prime(n,i+1)

num = int(input())
if is_prime(num):
    print("Prime")
else:
    print("Not prime")
