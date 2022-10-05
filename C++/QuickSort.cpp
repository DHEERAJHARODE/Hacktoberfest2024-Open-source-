// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
int partition(int a[], int lb, int ub)
{
	int pivot,start,end;
    pivot=a[lb]; 
	start=lb; 
    end=ub;
    while(start<end)
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while(a[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&a[start], &a[end]);
        }
        
    }
    swap(&a[lb], &a[end]);
    return end;
}
void quick_Sort(int a[],int lb,int ub)
{
	if (lb<ub)
	{
		int loc=partition(a,lb,ub);
        quick_Sort(a,lb,loc-1);
		quick_Sort(a,loc+1,ub);
	}
}
void print(int a[],int n)
{
    int t;
    for(t=0;t<n;t++)
    {
       cout<<a[t]<<" "; 
    }
    cout<<"\n";
}
int main()
{
int n;
cout<<"Enter the size of array:";
cin>>n;
int a[n];
cout<<"\nEnter the elements of array:";
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
quick_Sort(a,0,n-1);
cout<<"\nSorted array: ";
print(a,n);
return 0;
}
