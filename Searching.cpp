#include<stdio.h>
int pres=0;
void search(int arr[],int key,int high,int low,int n)
{
  int count=2;
  if(arr[high]==key)
  {
    pres=1;
    printf("Present %d",high);
  }
  else
  {
    if(key>arr[high])
    {
      low=high;
      high+=count;
      if(high>n)
      {
        search1(arr,low,key,n);
      }
      search(arr,key,high,low,n);
    }
    else
    {
      search2(arr,key,high,low);
    }
  }
}
void search1(int arr[],int low,int key,int n)
{
  for(int i=low;i<n;i++)
  {
    if(arr[i]==key)
    {
    pres=1;
    printf("Present %d",i);
    }
  }
}
void search2(int arr[],int key,int high,int low)
{
  for(int i=low;i<high;i++)
  {
    if(arr[i]==key)
    {
    pres=1;
    printf("Present %d",i);
    }
  }
}
int main()
{
  int cases,n,high=2,low=0;
  scanf("%d",&cases);
  while(cases--)
  {
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);
    int key;
    scanf("%d",&key);
    search(arr,key,high,low,n);
    if(pres==0)
    printf("\nNot Present %d\n",n);
  }
  return 0;
}
