//8.WAP to read 10 elements in an array and find the minimum.
#include <stdio.h>
int main(){
   int arr[10],i, min, location;
   for(i=0; i<10;i++){
      printf("Enter the %d number:- ", i+1);
      scanf("%d", &arr[i]);
   }
   min=arr[0];
   for(i=0; i<10; i++){
      if (arr[i]< min){
         min=arr[i];
         location = i+1;
      }
   }
   printf("The minimum number is %d", min);
   return 0;
}