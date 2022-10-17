# Code by Atharv Patil

# Time Complexity: O(n.logn)
# Space Complexity: O(n)


def MergeSort(l):
    if len(l) == 1:
        return
    left = l[:len(l)//2]
    right = l[len(l)//2:]
    MergeSort(left)
    MergeSort(right)
    i = j = k = 0
    while (i < len(left) and j < len(right)):
        if left[i] < right[j]:
            l[k] = left[i]
            i += 1
        else:
            l[k] = right[j]
            j += 1
        k += 1
    while (i < len(left)):
        l[k] = left[i]
        k += 1
        i += 1
    while (j < len(right)):
        l[k] = right[j]
        k += 1
        j += 1


l = list(map(int, input("Enter the list to be sorted: ").split()))
print()
MergeSort(l)
print()
print("Final array after sorting:", end=" ")
for i in l:
    print(i, end=" ")
print()

# Test Case
# Enter the list to be sorted: 1 29 3 1 -1 2 -3 9 10 -4

# Final array after sorting: -4 -3 -1 1 1 2 3 9 10 29
