n=int(input())
l = []
print("Enter Number in array")
for i in range(n):
    l.append(int(input()))

f=True
l.sort()
ans=int(input("Enter the number:"))
i,j=0,n-1
while(i<j):
    m=int((i+j)/2)
    if(l[m]>ans):
        j=m-1
    elif l[m]<ans:
        i=m+1
    else:
        print(f"{ans}Found at {m}")
        f=False
        break
if f:
    print("Not Found")