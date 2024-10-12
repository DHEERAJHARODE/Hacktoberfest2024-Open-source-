a=int(input())
s=[1]
for i in range(a):
        print(" "*(a-i)+" ".join(map(str,s)))
        k=[1]
        for j in range(len(s)-1):
            k.append(s[j]+s[j+1])
        k.append(1)
        s=k
