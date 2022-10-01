// 10.WAP to read 10 elements in an array and sort them in ascending order.
#include<stdio.h>
int main(){
    int arr[10],i, j, empt;
    printf("Enter the numbers:- ");
    for(i=0; i<10; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(arr[i]< arr[j]){
                empt = arr[i];
                arr[i]= arr[j];
                arr[j]= empt;
            }
        }

    }
    printf("\nThe numbers in ascending order is : ");
    for(i=0;i<10;i++)
    printf(" %d",arr[i]);
}