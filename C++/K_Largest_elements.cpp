#include<iostream>
#include<queue>
using namespace std;

int main(){
  
    // Defining the heap using STL here int specifies data type , vector<int> as the container , greater<int> is comparator to make it min heap.
  
    priority_queue<int,vector<int>,greater<int>>pq;

    int a[]={12,45,10,2,3,67};   // Defining the array
    
    int n= sizeof(a)/sizeof(a[0]);  // Allocating size
 
    int k=3;
    
    for(int i=0;i<n;i++){
                          
        // Inputting the elements
        pq.push(a[i]);

        // Checking That size of heap should be less than equal to k Otherwise pop element
        if(pq.size()>k){
            pq.pop();
        }
    }

 //Printing the elements
 while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }

 
 return 0;
}

/* 
Output :
12 45 67 
*/
