#include <stdio.h>
void main()
{   int i,j,n,c=0,max=0,mode=0;
    int a[100],t;
    float s=0,mean=0,median=0;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        s=s+a[i];
    }

    mean=s/n;
    printf("The Mean of the arrayis %f",mean);
    for(i=0;i<n;i++)
     {
         
       for(j=0;j<n;j++)
       {
          if(a[i]==a[j])
          c++;
       }
       if(c>max)
       {
        max=c;
        mode=a[i];
       
       }
     }
     printf("The mode is %d",mode);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
           if(a[j]>a[j+1])
           {
               t=a[j];
               a[j]=a[j+1];
               a[j+1]=t;
           }
        }
    }
    if((n%2)==0)
    median=(a[n/2]+a[(n+1)/2])/2;
    else
    median=a[n/2];
    printf("The median %f",median);
}