// Input Format: N = 3

// Result: 

// 3 3 3 3 3 

// 3 2 2 2 3 

// 3 2 1 2 3 

// 3 2 2 2 3 

// 3 3 3 3 3

 

// Input Format: N = 6

// Result:   

// 6 6 6 6 6 6 6 6 6 6 6 

// 6 5 5 5 5 5 5 5 5 5 6 

// 6 5 4 4 4 4 4 4 4 5 6 

// 6 5 4 3 3 3 3 3 4 5 6 

// 6 5 4 3 2 2 2 3 4 5 6 

// 6 5 4 3 2 1 2 3 4 5 6 

// 6 5 4 3 2 2 2 3 4 5 6 

// 6 5 4 3 3 3 3 3 4 5 6 

// 6 5 4 4 4 4 4 4 4 5 6 

// 6 5 5 5 5 5 5 5 5 5 6 

// 6 6 6 6 6 6 6 6 6 6 6



#include <bits/stdc++.h>
using namespace std;
void pattern22(int n){
    // Outer loop for no. of rows
    for(int i=0;i<2*n-1;i++){
        // inner loop for no. of columns.
        for(int j=0;j<2*n-1;j++){
            // Initialising the top, down, left and right indices of a cell.
            int top = i;
            int bottom = j;
            int right = (2*n - 2) - j;
            int left = (2*n - 2) - i;
      
            cout<<(n- min(min(top,bottom), min(left,right)))<<" ";}
        
            cout<<endl;
        
    }
    
}int main(){
            // Here, we are taking input from the user.
            int N;
            cout<<"Enter a number : "; 
            cin>>N;
            pattern22(N);
            return 0;
    
}
