// 7.WAP to read 10 elements in an array and find the maximum.
#include <stdio.h>
int main(){
   int arr[10],i,max, locate;
   for(i=0; i<10; i++){
      printf("Enter the %d number", i+1);
      scanf("%d", &arr[i]);
   }
   max= arr[0];
   for (i=0; i<10; i++){
      if(arr[i]> max){
         max= arr[i];
         locate = i+1;
      }
   }
   printf("The max value in array is %d and located ate %d position\n", max, locate);
}