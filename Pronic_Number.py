def checkPronic(Number):
    i = 0
    flag = 0
    while i <= Number:
        if Number == i * (i + 1):
            flag = 1
            break
        i = i + 1
    return flag
print("Pronic Numbers are:-")
for i in range(1, 101):
    if(checkPronic(i) == 1):
        print(i)
