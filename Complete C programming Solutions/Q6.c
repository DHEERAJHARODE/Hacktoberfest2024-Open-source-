// 6.WAP to read 10 elements in an array and search for a particular number among the array list.
#include <stdio.h>
int main(){
   int arr[10],i, search, stop;
   for(i=0; i<10; i++){
      printf("Enter the %d number:- ", i+1);
      scanf("%d", &arr[i]);
   }
   printf("Enter a number you want to search :- ");
   scanf("%d", &search);
   printf("Searching for %d in the array!\n", search);
   for(i=0; i<10; i++){
      if(arr[i] == search){
         stop=1;
         break;
      }
   }
   if(stop==1){
      printf("Found sucessfully!");
   }else{
      printf("Not found!");
   }
   return 0;
}