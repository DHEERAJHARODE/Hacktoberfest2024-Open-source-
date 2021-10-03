//C program to find smallest and largest element in array.
#include <stdio.h>
#include <conio.h>

int main(){
    int arr[10],minValue,maxValue=0;
    printf("Enter ten numbers :\n");
    for(int i=0;i<10;i++){
        scanf("%d" , &arr[i]);
        if(arr[i]>maxValue){
            maxValue=arr[i];
        }
    }
    minValue=maxValue;
    for(int i=0;i<10;i++){
        if(arr[i]<minValue){
            minValue=arr[i];
        }
    }
    printf("Minimum Value = %d\n" , minValue);
    printf("Maximum Value = %d\n" , maxValue);
    getch();
}
