// Enter a number : 3
//   A  
//  ABA 
// ABCBA

// Enter a number : 8
//        A       
//       ABA      
//      ABCBA     
//     ABCDCBA    
//    ABCDEDCBA   
//   ABCDEFEDCBA  
//  ABCDEFGFEDCBA 
// ABCDEFGHGFEDCBA


#include <bits/stdc++.h>
using namespace std;
void pattern(int N){
    // Outer loop for the number of rows.
    for(int i=0;i<N;i++){
        // for printing the spaces.
        for(int j=0;j<N-i-1;j++){ cout<<" ";}
        // for printing the characters.
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for(int j=1;j<=2*i+1;j++){
            cout<<ch;
            if(j <= breakpoint) ch++;
            else ch--;
            
        }
        // for printing the spaces again after characters.
        for(int j=0;j<N-i-1;j++){
            cout<<" ";
            
        }
           
            cout<<endl;
        
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
