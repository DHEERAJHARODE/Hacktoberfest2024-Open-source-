import java.util.Arrays;
class Sorting
{
	public static void main(String[] args)
	{
	    int[] arr = { 7, 23, 0, 1, 12, 72,-31, 6, 100, 88, 4 };
		new Sorting().sort_function(arr);
		for (int i = 0; i < arr.length; i++)
			System.out.print(arr[i] + " ");
	}
	
	public void sort_function(int array[])
	{
		for (int i = 1; i < array.length; i++)
		{
			int x = array[i];
			int j = Math.abs(Arrays.binarySearch(array, 0,i, x) + 1);
			System.arraycopy(array, j,array, j + 1, i - j);
			array[j] = x;
		}
	}
}

