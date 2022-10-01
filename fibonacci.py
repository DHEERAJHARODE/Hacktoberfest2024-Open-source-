cube = lambda x:x**3 # complete the lambda function 

def fibonacci(n):
    # return a list of fibonacci numbers
    List = [0, 1]
    for i in range(2, n):
        List.append(List[i-1] + List[i-2])
    
    return(List[0:n])
    
    
if __name__ == '__main__':
    n = int(raw_input())
    print map(cube, fibonacci(n))
