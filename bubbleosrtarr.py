def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

def main():
    # Input array from the user
    try:
        input_str = input("Enter space-separated numbers to sort: ")
        arr = list(map(int, input_str.split()))
        
        # Call the bubble_sort function to sort the array
        bubble_sort(arr)

        print("Sorted array is:", arr)
    except ValueError:
        print("Invalid input. Please enter space-separated numbers.")

if __name__ == "__main":
    main()
