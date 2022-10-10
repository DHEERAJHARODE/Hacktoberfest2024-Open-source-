def make_triangle(size):
    n = size * 2
    for i in range(1, size+1):
        print(' '*n, end='') # repet space for n times
        print('* '*(i)) # repeat stars for i times
        n-=1



if(__name__ == '__main__'):
    size = input("Enter the size of triangle: ")
    if(size.strip().isdigit()):
        make_triangle(int(size))
    else:
        print("Your input it's not a number!!!")