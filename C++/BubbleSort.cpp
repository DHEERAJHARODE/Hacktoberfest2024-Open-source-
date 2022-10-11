#include<iostream>
using namespace std;
int main(){
   int n;
    cin>>n;
    int arr[n];
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
    for(int i=1;i<5;i++){
        for(int j=0;j<5;j++){
           if(arr[j]>arr[j+1]){
            int temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
           }
           cout<<arr[j];
        }
         break;
        }
    }
