// A binary search C++ program using pointers.
#include<iostream>
using namespace std;
int binarysearch(int *arr, int ele, int *ptrlast, int **ptr_to_value);
int main()
{ int arr[20],n,i;
  int found,value;
  int *ptrlast,*ptr_to_value;
  int ele;
  ptr_to_value=NULL;
  cout<<"Enter the number of elements"<<endl;
  cin>>n;
  cout<<"Enter the elements"<<endl;
  for(i=0;i<n;i++)
  cin>>arr[i];
  cout<<"Enter the element to be searched";
  cin>>ele;
  ptrlast=arr+n-1;
  found=binarysearch(arr,ele,ptrlast,&ptr_to_value);
  if(found==1)
  cout<<"Element "<<*ptr_to_value<<" is found";
  else
 cout<<"Element is not found";
}
int binarysearch(int *arr, int ele, int *ptrlast, int **ptr_to_value)
{ int *firstptr, *midptr, *lastptr;
  firstptr=arr;
  lastptr=ptrlast;
  while(firstptr<=lastptr)
  { midptr = firstptr+(lastptr-firstptr)/2;
    if(ele>*midptr)
      { firstptr=midptr+1;
      }
    else if(ele<*midptr)
      {
        lastptr=midptr-1;
      }
    else
      {
          firstptr=lastptr+1;
      }


  }
*ptr_to_value=midptr;
 return(ele==*midptr);

}
