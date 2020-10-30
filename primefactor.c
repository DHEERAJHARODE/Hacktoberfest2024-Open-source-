\\ PRIME FACTOR OF ANY NUMBER


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i, y, flag=0;
    printf("Enter an integer \n");
    scanf("%d",&x);
    for(i=2; i<=x; i++){
        flag=0;
        if(x%i==0){
            for(y=2; y<i; y++){
                if(i%y==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                printf("%d, ",i);
            }

        }
    }
    return 0;
}
