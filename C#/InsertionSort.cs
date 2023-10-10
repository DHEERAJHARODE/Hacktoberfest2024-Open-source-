using System;

class InsertionSort
{
    public static void Sort(int[] arr)
    {
        for (int i = 1; i < arr.Length; i++)
        {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }

    public static void Main(string[] args)
    {
        int[] arr = { 12, 4, 5, 6, 7, 3, 1, 15 };

        Console.Write("Original Array: ");
        PrintArray(arr);

        Sort(arr);

        Console.Write("Sorted Array: ");
        PrintArray(arr);
    }

    private static void PrintArray(int[] arr)
    {
        foreach (var item in arr)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();
    }
}
