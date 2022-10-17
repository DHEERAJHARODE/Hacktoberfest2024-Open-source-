def TOH(number, s, d, a):
    if number == 1:
        print("Move disk 1 from source", s, "to destination", d)
        return
    TOH(number - 1, s, a, d)
    print("Move disk", number, "from source", s, "to destination", d)
    TOH(number - 1, a, d, s)


n = 3
TOH(n, 'A', 'B', 'C')
