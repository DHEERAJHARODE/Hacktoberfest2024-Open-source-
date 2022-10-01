// 3.WAP to read 10 elements in an array and copy all the elements to another array.
#include <stdio.h>
int main(){
    int from[10], destiny[10], i;
     printf("Enter the numbers :- ");
    for (i=0; i< 10; i++){
        scanf("%d", &from[i]);
    }
    for (i=0; i< 10; i++){
        destiny[i] = from[i];
    }
    printf("\nElement in first array\n");
    for (i=0; i< 10; i++)
    {
        printf("%d\t", from[i]);
    }
    printf("\nElements in second array\n");
    for (i=0; i< 10; i++){
        printf("%d\t", destiny[i]);
    }
    return 0;
}
