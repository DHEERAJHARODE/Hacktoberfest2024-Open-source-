#include<iostream>
 
using namespace std;
 
int main()
{
    int i,j,n,loc,temp,min,a[30];
    cout<<"Enter the list  length :";
    cin>>n;
    cout<<"\nEnter the numbers in list\n";
 
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
 
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }
        }
 
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
 
    cout<<"\nYour  Sorted list -> \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
 
    return 0;
}
