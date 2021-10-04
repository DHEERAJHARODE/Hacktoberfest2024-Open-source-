/* BUBBLE SORT PROGRAM IN C USING FUNCTION - BUBBLESORT.C */

#include<stdio.h>
#include<stdlib.h>

void bubblesort (long a[],long size)
{
  int temp, i, j;
  for (i = 0; i < (size-1); i++)
    {
      int swapped = 0;//flag variable
      for (j = 0; j < (size-i-1); j++)
	{
	  if (a[j] > a[j + 1])
	    {
	       // swapping
	      swapped = 1;
	      temp = a[j];
	      a[j] = a[j + 1];
	      a[j + 1] = temp;
	    }
	}
      if (swapped == 0)//if no swapping in the previous iteration i.e. sorting done
	break;
    }
}


void main ()
{
  long int n, i;

  printf ("\n Enter the size of the array: ");
  scanf ("%ld", &n);

  long a[n];

  printf ("\n Enter the array elements: \n");

//   fetch input
  for (i = 0; i < n; i++)
    scanf ("%ld", &a[i]);
    
  bubblesort (a, n);
  
//   print the output
  printf ("\n The sorted array is\n");
  for (i = 0; i < n; i++)
    printf ("%ld ", a[i]);
}
