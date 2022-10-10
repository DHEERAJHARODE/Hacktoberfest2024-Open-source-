#include <stdio.h>
int main(){
    float m1,m2,m3,m4,m5,total,avg; //single line comment

    /*multi line comment
    xxxxxx
    yyyyyy
    */
    printf("Enter marks in math- ");
    scanf("%f" , &m1);
    printf("Enter marks in physics- ");
    scanf("%f" , &m2);
    printf("Enter marks in chemistry- ");
    scanf("%f" , &m3);
    total = m1+m2+m3;
    avg = total/3;
    printf("Your total pcm marks - %f" ,total );
    printf("\nAverage pcm marks- %f\n", avg);
    if (total>270){
        printf("Grade = A+\n");
    }
    else if (total>240 && total<270){
        printf("Grade = A\n");
    }
    else {printf("WOrk hard");};
}  
