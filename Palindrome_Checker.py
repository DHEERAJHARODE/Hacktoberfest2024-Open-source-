def isPalindrome(x):
    t = int(x)
    r = 0
    while t > 0:
        m = t % 10
        r = r*10+m
        t = t//10
    if x == r:
        return True
    else:
        return False

