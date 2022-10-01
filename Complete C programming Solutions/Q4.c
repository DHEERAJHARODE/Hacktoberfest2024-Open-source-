// 4.WAP to read 10 elements in an array and copy all the elements in reverse order to an another array.
#include<stdio.h>
int main(){
    int arr[10], i,j, rev[10];
    for(i=0; i<10; i++){
        printf("Enter the %d element:- ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("The reversed array is:- ");
     for(i=0, j=9; i<=0, j>=0; i++, j--){
        rev[j]= arr[i];
    }
    for(j=0; j<10; j++){
        printf("%d ", rev[j]);
    }

    return 0;

}