// Bubble sort

#include <stdio.h>
void Bubble_Sort(int arr[],int n)
{
    int i,j,temp;
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                
            }
        }
    }
}
int main() {
         
         int i,n,arr[5];
         printf("Enter the size: \n");
         scanf("%d",&n);
	 printf("Enter the Elements: \n");
         for(i=0;i<n;i++)
         {
             scanf("%d",&arr[i]);
         }
         printf("the unsorted array:\n");
         for(i=0;i<n;i++)
         {
             printf("%d  ",arr[i]);
             
         }
         printf("\n");
         Bubble_Sort(arr,n);
          printf("the sorted array:\n");
         for(i=0;i<n;i++)
         {
             printf("%d  ",arr[i]);
             
         }
         
         
}

