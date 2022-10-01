//9.WAP to count the frequency of each element of an array.
#include<stdio.h>
int main(){
   int i,n, arr[n], count,j, count2;
   printf("Enter the no of array you want to make: ");
   scanf("%d", &n);
   for (i=0; i<n; i++){
      printf("Enter the %d number of array", i+1);
      scanf("%d", &arr[i]);
   }
   for(i=0; i<n; i++){
      count=0;
      for(j=0; j<n; j++){
         if (arr[i]==arr[j]){
            count++;
         }
      }
      count2=0;
      for (j=0; j<i; j++){
         if(arr[i]==arr[j]){
            count2++;
         }
      }
      if(count2 < 2)
      printf("The frequency of %d is %d\n", arr[i], count);

   }	     
 	return 0;
}