// This is min binary heap

#include<stdio.h>
#include<stdlib.h>
int n=13;
void Bottom_up_heapify(int *a,int i)
{
	int p=(i-1)/2;
	while(i>0 && a[i]<a[p])
	{
		int temp = a[i];
		a[i] = a[p];
		a[p] = temp;
		i = p;
		p = (i-1)/2;
	}
}
void Top_down_heapify(int *a,int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int min;
	while(r<n)
	{
		if(a[l] > a[r])
			min =r;
		else
			min =l;
		if(a[i] > a[min])
		{
			int temp = a[i];
			a[i] = a[min];
			a[min]=temp;
			i = min;
			l = 2*i+1;
			r = 2*i+2;
			if( l == n-1 && a[l] < a[i])
			{
				int temp = a[l];
				a[l] = a[i];
				a[i]=temp;	
			}
		}
		else
			break;
	}
}

void Build_Heap(int *a)
{
	int i=n/2;
	while(i>=0)
	{
		Top_down_heapify(a,i);
		i--;
	}
	
}

void Add_element(int *a,int key)
{
	a[n] = key;
	Bottom_up_heapify(a,n);
}
void Decrease_key(int *a,int i,int x)
{
	a[i] -= x;
	Bottom_up_heapify(a,i);
}
void Change_key(int *a,int i,int x)
{
	if(a[i] < x)
	{
		a[i] = x;
		Top_down_heapify(a,i);
	}
	else
	{
		a[i]=x;
		Bottom_up_heapify(a,i);
	}
}
void Delete_min(int *a)
{
	a[0] = a[n-1];
	n = n-1;
	Top_down_heapify(a,0);
}
void Delete_key(int *a,int i)
{
	Decrease_key(a,i,a[0]-1);
	Delete_min(a);
}

int main()
{
	int a[15] = {3,12,41,121,2,323,76,2,33,1,65,4,3,0,0};
	Build_Heap(a);
	for (int i=0;i<15;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}