def collatz(number):
  steps=0
  if number>1:

    while number !=1:
      if number %2==0:
        print(int(number))
        number=number//2
        steps += 1
      else:
        print(int(number))
        number=number*3+1
        steps += 1
    print(f'collatz sequence finished in {steps} steps')
  else:
    print("please Enter a number greater than 1")
        
number=int(input("choose any integer greater than 1: "))
collatz(number)