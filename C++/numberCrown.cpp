// Enter a number : 5
// 1        1
// 12      21
// 123    321
// 1234  4321
// 1234554321

// Enter a number : 9
// 1                1
// 12              21
// 123            321
// 1234          4321
// 12345        54321
// 123456      654321
// 1234567    7654321
// 12345678  87654321
// 123456789987654321


#include <bits/stdc++.h>
using namespace std;
void pattern(int N){
   
    int spaces = 2*(N-1);
    // Outer loop for the number of rows.
    for(int i=1;i<=N;i++){
        // for printing numbers in each row
        for(int j=1;j<=i;j++){ cout<<j;}
        // for printing spaces in each row
        for(int j = 1;j<=spaces;j++){ cout<<" ";}
        // for printing numbers in each row
        for(int j=i;j>=1;j--){ cout<<j;}
       
        cout<<endl;
        // After each iteration nos. increase by 2, 
        spaces-=2;
        
    }
    
}
int main(){
    // Here, we are taking input from the user.
    int N;
    cout<<"Enter a number : ";
    cin>>N;
    pattern(N);
    return 0;
    
}


