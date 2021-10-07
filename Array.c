//C program to find smallest and largest element in array.
#include <stdio.h>
#include <conio.h>

int main(){
    int arr[100],min,max,size;

    //input the size of the array
    printf("Enter the size of the Array : ");
    scanf("%d",&size);

    //input the elements of the array
    printf("Enter the elements(numbers) of the Array : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d" , &arr[i]);
    }

    min=max=arr[0];

    //for finding the max. and min. values
    for(int i=1;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }

        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    printf("Minimum Value = %d\n" , min);
    printf("Maximum Value = %d\n" , max);
    getch();
}
