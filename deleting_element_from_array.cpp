#include<iostream>
using namespace std;
#define MAX 5

int deletion(int arr[],int Size){
  if(Size>0){
    int pos,val;
    cout<<"Enter the position of element to be deleted: ";
      cin>>pos;
    if(pos<Size && pos<MAX){
      val=arr[pos];
      for(int i=pos;i<=Size-1;i--){
      arr[i]=arr[i+1];
    }
      Size--;
      for(int i=0;i<Size;i++){
        cout<<arr[i]<<" ";
      }
      
      else{
        cout<<"Invalid"<<endl;
      }
      
      else{
        cout<<"Underflow"<<endl;
      }
      return Size;
    }

int main(){
  int Size=4;
  int arr[5];
  cout<<"Enter elements of array: ";
  for(int i=0;i<5;i++){
    cin>>arr[i];
  }
 deletion(arr,Size);
  return 0;
}
