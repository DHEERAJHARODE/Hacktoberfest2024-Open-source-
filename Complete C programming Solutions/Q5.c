// 5.WAP to separate odd and even integers in separate arrays.
#include <stdio.h>
int main()
{

   int  i, odd[10], even[10], arr[10], x = 0, w = 0;
   
   for (i = 0; i < 10; i++)
   {
      printf("Enter %d number:- ", i + 1);
      scanf("%d", &arr[i]);
   }
   for (i = 0; i < 10; i++)
   {
      if (arr[i] % 2 == 0)
      {
         odd[x] = arr[i];
         x++;
      }
      else
      {
         even[w] = arr[i];
         w++;
      }
   }
   printf("The odd numbers are :- ");
   for (i = 0; i < x; i++)
   {
      printf("%d ", odd[i]);
   }
   printf("\n The even numbers are:- ");
   for (i = 0; i < w; i++)
   {
      printf("%d ", even[i]);
   }
}
