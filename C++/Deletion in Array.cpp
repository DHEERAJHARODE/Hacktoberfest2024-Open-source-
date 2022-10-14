#include<iostream>
using namespace std;
int n;
void get(float arr[],int n)
{ 
 for(int i=0;i<n;i++)
{ cin>>arr[i];
}
  }
float delete_array(float arr[], int no_elements, int position)
{
float x;
if(position<=0||position>no_elements)
{ cout<<"Invalid position Cant Delete"<<endl;
return 0;
}
else 
{ x=arr[position-1];
for(int i=position-1;i<no_elements;i++)
{ arr[i]=arr[i+1];
}
n--;
}
return x;
}
void display(float arr[],int n)
{ for(int i=0;i<n;i++)
{ cout<<arr[i]<<" ";
}
}
int main()
{float arr[100];
int a;
cout<<"Enter Number of elements you want to add"<<endl;
cin>>n;
cout<<"Enter the elements"<<endl;
get(arr,n);
cout<<"Enter position that you want to delete"<<endl;
cin>>a;
delete_array(arr,n,a);
cout<<"The modified/original(if invalid position) list is: ";
display(arr,n);
return 0;
}