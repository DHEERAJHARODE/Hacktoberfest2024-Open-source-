/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int result(int arr[], int n, int val){
    int i = 0;
    int j = n-1;
    
    while (j > i){
        
        if (arr[i] + arr[j] == val){
            cout << "Elements: " << i << ' ' << j << endl;
            return 0;
            
        }
        
        else if (arr[i] + arr[j] < val){
            i++;
        }
        
        else{
            j--;
        }
         
    }
}

int main()
{
    int arr[] = {2, 3, 5, 8, 9, 10, 11};
    int val = 17;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    result(arr, n, val);
    return 0;
}