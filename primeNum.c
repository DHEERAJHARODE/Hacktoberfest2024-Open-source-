#include<stdio.h>

int main(){
    int n, count = 0;
    scanf("%d", &n);

    
    for(int i=2; i<n/2; i++){
        if(n%i == 0){
            count = 1;
            break;
        }
    }

    if(n==1){
        printf("This is neither a prime nor composite");
    }
    else if(count ==0) {
        printf("This is a prime number");
    }
    else
        printf("This is not a prime number");

    return 0;
}
