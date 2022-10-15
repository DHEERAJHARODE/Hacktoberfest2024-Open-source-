#!/bin/python3

def input_value(bar):
    foo = input(bar)
    foo = check_num(foo, bar)
    return foo

def check_num(foo, bar):
    try:
        foo = int(foo)
        if int(foo) > 0:
            return foo
        else:
            error_msg(foo)
            foo = input(bar)
            return foo
    except:
        error_msg(foo)
        foo = input(bar)
        return foo

def error_msg(foo):
    print(f"Die Eingabe von {foo} ist ungültig. Bitte geben Sie eine positive Ganzzahlen an.")

def tree(foo):
    bar = "*" 
    for i in range(1, foo + 1):
        print("{f:^80}".format(f=bar))
        bar += "**"
    if foo > 0 and foo < 10:
        print("{f:^80}".format(f="#"))
        print("{f:^80}".format(f="#"))
    elif foo > 11 and foo < 20:
        print("{f:^80}".format(f="###"))
        print("{f:^80}".format(f="###"))
        print("{f:^80}".format(f="###"))
        print("{f:^80}".format(f="###"))
    elif foo > 21:
        print("{f:^80}".format(f="#####"))
        print("{f:^80}".format(f="#####"))
        print("{f:^80}".format(f="#####"))
        print("{f:^80}".format(f="#####"))
        print("{f:^80}".format(f="#####"))
        print("{f:^80}".format(f="#####"))
        print("{f:^80}".format(f="#####"))

def main():
    tree(input_value("Wie groß soll der Baum werden? : "))

main()