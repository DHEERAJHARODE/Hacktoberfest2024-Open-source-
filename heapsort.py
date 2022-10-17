# Coded by Atharv Patil

from collections import *


# Time Complexity: O(n.log(n))
# Space Complexity: O(1)


def heapify(arr, N, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < N and arr[largest] < arr[l]:
        largest = l

    if r < N and arr[largest] < arr[r]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, N, largest)


def heapsort(arr):
    N = len(arr)

    for i in range(N//2 - 1, -1, -1):
        heapify(arr, N, i)

    q = deque()
    q.append(0)
    d = defaultdict(list)
    cnt = 0
    while q:
        qq = len(q)
        for i in range(qq):
            k = q.popleft()
            d[cnt].append(arr[k])
            if 2*k+1 < N:
                q.append(2*k+1)
            if 2*k+2 < N:
                q.append(2*k+2)
        cnt += 1

    for i in range(len(list(d.keys()))):    # It makes a tree a like visualisation
        print("level", i, ":", *d[i])       # of the heap

    for i in range(N-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)


a = list(map(int, input("Enter the array to be sorted: ").split()))
heapsort(a)
n = len(a)
print("Sorted array:", end=" ")
for i in range(n):
    print(a[i], end=" ")


# Test Case

# Enter the array to be sorted: 8 9 1 2 34 4 1 0 3 9 3 -1 9 -34

# level 0 : 34
# level 1 : 9 9
# level 2 : 3 9 4 1
# level 3 : 0 2 8 3 -1 1 -34

# Sorted array: -34 -1 0 1 1 2 3 3 4 8 9 9 9 34
