//n queen problem
#include<stdio.h>
#include<math.h>
int b[20];
int check(int row,int col)
{
	int i;
	for(i=0;i<row;i++)
	{
		if(b[i]==col)
		  return 0;
		else if(abs(b[i]-col)==abs(i-row))
		   return 0;
	}
	return 1;
}
void display(int n)
{
	   int i,j;
	   printf("\n\n\n");
 for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i]==j)
			 printf("\tQ");
			else
			   printf("\t-");
		}
		printf("\n");
	}

       for(i=0;i<n;i++)
         printf("%d ",b[i]);
}
void queen(int row,int n)
{
	int col;
	for(col=0;col<n;col++)
	{
		if(check(row,col)==1)
		{
			b[row]=col;
			if(row==n-1)
			  display(n);
			else
			  queen(row+1,n);
		}
	}
}
int main()
{
	int n;
	printf("Enter no of queens: ");
	scanf("%d",&n);
	printf("\nThe possible placements of the queen where no collision will occur among them:\n");
	queen(0,n);
}


