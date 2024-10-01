def quicksort(A,l,r):
    p1 = l+1

    if r-l<=1:
        return()

    for p2 in range(l+1,r):
        if A[p2]<=A[l]:
            (A[p1],A[p2]) = (A[p2],A[p1])
            p1+=1
    (A[l],A[p1-1]) = (A[p1-1],A[l])
    quicksort(A,l,p1-1)
    quicksort(A,p1,r)

    return A

print(quicksort([9,8,7,6,5,4],0,6))