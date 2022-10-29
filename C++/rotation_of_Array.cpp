#include<iostream>
using namespace std;
int main() {
 int t; cin>>t;
 while(t--){
 	int n,k,i,j;
 	cin>>n>>k;
    int arr[n],temp[k];
    for(i=0;i<n;i++){ //inserting the element
        cin>>arr[i];
    }
 	for(i=0;i<k;i++){  //coping element into temp 
 		temp[i]=arr[i];
 	}
 	for(i=0;i<=n-k-1;i++){ //shifting of elements
       arr[i]=arr[i+k];
 	}
 	for(i=n-k,j=0;i<n;i++){ 

 		arr[i]=temp[j++];
 	} 
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

 return 0;
}