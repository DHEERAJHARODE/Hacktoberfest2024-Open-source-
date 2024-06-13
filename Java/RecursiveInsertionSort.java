// Recursive Java program for insertion sort

import java.util.*;

public class Sorting
{
	static void recur_insertion_sort(int arr[], int size)
	{
		if (size <= 1)
			return;
		recur_insertion_sort( arr, size-1 );
		int last = arr[size -1];
		int j = size-2;
		while (j >= 0 && arr[j] > last)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = last;
	}
	public static void main(String[] args)
	{
		int arr[] = {2, 117, -13, 85, 6};
		recur_insertion_sort(arr, arr.length);
		System.out.println(Arrays.toString(arr));
	}
}
