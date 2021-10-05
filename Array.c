//C program to find smallest and largest element in array.
#include <stdio.h>
#include <conio.h>

int main(){
    int arr[100],minValue,maxValue,size;

    //input the size of the array
    printf("Enter the size of the Array :\n");
    scanf("%d",&size);

    //input the elements of the array
    printf("Enter the elements(numbers) of the Array : \n");
    for(int i=0;i<size;i++)
    {
        scanf("%d" , &arr[i]);
    }

    minValue=maxValue=arr[0];

    //for finding the max. and min. values
    for(int i=1;i<size;i++)
    {
        if(arr[i]>maxValue)
        {
            maxValue=arr[i];
        }

        if(arr[i]<minValue)
        {
            minValue=arr[i];
        }
    }
    printf("Minimum Value = %d\n" , minValue);
    printf("Maximum Value = %d\n" , maxValue);
    getch();
}
