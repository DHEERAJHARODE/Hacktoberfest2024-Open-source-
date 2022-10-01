/*Program to implement binary search*/
#include<iostream.h>
#include<conio.h>
class search
{
	int a[20],n;
	public:void read(void);
	       void bsearch(void);
};
void search::read()
{
	cout<<"\n Enter the size of the array:";
	cin>>n;
	cout<<"\n Enter the sorted array elements:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

}
void search::bsearch()
{
	int i,beg=0,end=n-1,mid,loc=0,item;
	cout<<"\n Enter the item to be searched:";
	cin>>item;
	mid=int(beg+end)/2;
	while((beg<end)&&a[mid]!=item)
	{
		if(item<a[mid])
		{
			end=mid-1;
		}
		else
		{
			beg=mid+1;
		}
		mid=int(beg+end)/2;
	}
	if(a[mid]==item)
	{
		loc=mid+1;
		cout<<"\n Search sucessful!! \n item is foud at pos:"<<loc;
	}
	else
	{
		cout<<"\n The item is not in the array!!";
	}
}
int main()
{
	clrscr();
	search obj;
	obj.read();
	obj.bsearch();
	getch();
	return 0;
}