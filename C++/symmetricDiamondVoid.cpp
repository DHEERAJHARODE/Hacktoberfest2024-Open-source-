// Enter a number : 3
// ******
// **  **
// *    *
// *    *
// **  **
// ******
  
// Enter a number : 5
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********

#include <bits/stdc++.h>
using namespace std;
void pattern(int N){
  
    int iniS = 0;
    for(int i=0;i< N;i++){
        //for printing the stars in the row.
        for(int j=1;j<=N-i;j++){ cout<<"*";}
        //for printing the spaces in the row.
        for(int j=0;j<iniS;j++){ cout<<" ";}
        //for printing the stars in the row.
        for(int j=1;j<=N-i;j++){ cout<<"*";}
  
        iniS+=2;
    
        cout<<endl;}
     
        for(int i=1;i<=N;i++){
            //for printing the stars in the row.
            for(int j=1;j<=i;j++){ cout<<"*";}
            //for printing the spaces in the row.
            for(int j=0;j<iniS-2;j++){ cout<<" ";}
            //for printing the stars in the row.
            for(int j=1;j<=i;j++){ cout<<"*";}
 
            iniS-=2;
          
            cout<<endl;}
    
            }
            int main(){
                // Here, we are taking input from the user.
                int N;
                cout<<"Enter a number : ";
                cin>>N;
                pattern(N);
                return 0;
                
            }
