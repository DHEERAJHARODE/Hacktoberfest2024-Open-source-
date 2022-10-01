// 2.WAP to read 10 elements in an array and count the occurrence of odd and even numbers.
#include <stdio.h>
int main(){
   int a[9],i,even=0,odd=0;

    for(i=0; i<10; i++)
    {
        printf("Enter %d element in array : ", i+1);
        scanf("%d",&a[i]);
    }

     for(i=0; i<10; i++)
    {
          if(a[i]%2==0)
          even++;
          else
          odd++;

    }
     printf("even numbers in array: %d",even);
     printf("\n odd numbers in array: %d",odd);

    return 0;
}