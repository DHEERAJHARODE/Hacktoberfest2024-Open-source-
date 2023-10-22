// Optimized javaScript implementation
// of Bubble sort
// An optimized version of Bubble Sort
function bubbleSort(arr, n)
{
	var i, j, temp;
	var swapped;
	for (i = 0; i < n - 1; i++) 
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				// Swap arr[j] and arr[j+1]
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}

		// IF no two elements were 
		// swapped by inner loop, then break
		if (swapped == false)
		break;
	}
}

// Function to print an array 
function printArray(arr, size)
{
var i;
for (i = 0; i < size; i++)
	console.log(arr[i] + " ");
}

// Driver program
var arr = [ 64, 34, 25, 12, 22, 11, 90 ];
var n = arr.length;
bubbleSort(arr, n);
console.log("Sorted array: ");
printArray(arr, n);

// This code is contributed shivanisinghss2110
