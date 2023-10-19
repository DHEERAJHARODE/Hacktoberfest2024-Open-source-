number=int(input("enter the number:"))
if(number>0):
  
  steps=0
  factorial=1
  for i in range(1,number+1):
        factorial*=i
        steps+=1
        print("factorial of %d in iteration %d id %d"%(number,steps,factorial))  
else:
  print("factorial of negative numbers are not possible")