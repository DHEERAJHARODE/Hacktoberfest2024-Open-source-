//github.com/hamsof
//hafiz abdulmanan

#include<stdio.h>
int main()
{
    int arr[10]={1,2,3,4,12,14,16,10,20,22};

    int max=0;
    int pre_max=-1;
    for(int i=0;i<10;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
     for(int i=0;i<10;i++)
    {
        if(arr[i] < max && arr[i]> pre_max)
        {
            pre_max= arr[i];
        }
    }
    printf("%d",pre_max);


    int arr[10]={1,2,3,4,12,14,16,10,20,22};
    int largest=0;int second_largest=0;
    for(int i=0;i<10;i++)
    {
        if(arr[i]>largest)
        {
            second_largest=largest;
            largest=arr[i];
        }
    }
    printf("\n%d %d ",largest,second_largest);
    return 0;
}