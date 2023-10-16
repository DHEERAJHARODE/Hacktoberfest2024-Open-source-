"""Fahrenheit to Celcius"""
input_var = input("if you want to convert from Fahrenheit to Celcius please select 1 and then the temperature like that \"1,34\", if you want to convert from Celcius to Fahrenheit select 2 like that \"2,55\"")
x = []
x = input_var.split(",")

if x[0] == "1":
    print(str((float(x[1]) - 32) * (5 / 9)) + "°C")
elif x[0] == "2":
    print(str((float(x[1]) * (9 / 5)) + 32) + "°F")
else:
    print("please select either option 1 or option 2")