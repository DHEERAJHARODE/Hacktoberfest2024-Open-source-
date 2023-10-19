import random
low=int(input("enter the lower bound:"))
high=int(input("enter the higher bound:"))

n=random.randint(low,high)
max_attempt=7



print("let's play guessing game")
print(f"you have to choose a number between {low} and {high}")
print("you have ",max_attempt," to guess your number")

for attempt in range(1,max_attempt+1):
    num=int(input("Enter your number:"))
    if num<n:
            #if num-n <= close:
                #print("you are very close to your number.think of a higher number")
            #else:    
                print('your guess is low. think of a higher number.your remaining attempts are ',max_attempt-attempt)
    elif num>n:
            #if n-num>=close:
               # print("you are close to your guessed number.think of a lower number") 
            #else:       
                print("your guess is high. think of a lower number .your remaining attempts are ",max_attempt-attempt)
    else:
        print("congrulation you have guessed the right number")
        break

    
print("your attempts are over , try again")       

   

