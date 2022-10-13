import random
a = ['a','b','c','d','e','f','g','h']
b = ['1','2','3','4','5','6','7','8']
c = 0
d = 0
print('0 for white and 1 for black, CTRL+C when you have finished.')
try:
    while 1:
        n = random.randint(0,7)
        m = random.randint(0,7)
        print(a[n]+b[m])
        if n%2==1 and m%2==1:
            r = '1'
        elif n%2==0 and m%2==0:
            r = '1'
        else:
            r = '0'
        print('White or Black : ')
        s = input()
        if s == r:
            c = c + 1
        d = d + 1
        if r =='1':
            print('Black')
        else:
            print('White')
        print()
except KeyboardInterrupt:
    print('You got ' + str(c) + ' correct guesses out of ' + str(d))