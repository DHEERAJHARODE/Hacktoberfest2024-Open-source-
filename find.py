sentence=input("enter a sentence:")

num_words=0
num_digits=0
up=0
lo=0

for char in sentence:
    if char.isdigit():
        num_digits+=1
    elif char.islower():
        lo+=1
    elif char.isupper():
        up+=1
num_words=len(sentence.split())
print("the number of words:",num_words)
print("the number of digits:",num_digits)
print("the number of uppercase words:",up)
print("the number of lowercase words:",lo)

