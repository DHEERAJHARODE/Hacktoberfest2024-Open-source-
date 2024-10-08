//Recursive algorithm for linear search
#include<stdio.h>
#include<conio.h>

int search(int [20],int a,int n);

int main()
{
	int arr[20],a,n,i,p;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter any %d numbers: \n",n);
	for(i=0;i<n;i++)
	{
		printf("Number %d: ",i+1);
		scanf("%d",&arr[i]);
	}	
	printf("Enter the number to search: ");
    scanf("%d",&a);
    p=search(arr,a,n);
    if (p==-1)
    {
        printf("Not found.\n");
    }
    else
    {
        printf("Found at %d.\n",p);
    }
	getch();
}

int search(int arr[],int a,int n)
{
	if (arr[n]==a)
        return n;
    else if (n<0)
        return -1;
    else
        return search(arr,a,n-1);
}
