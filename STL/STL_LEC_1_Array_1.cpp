/*  if we declare an array and don't initialize values then in int main it will have garbage values 
where if we declare them in global space it will be initialized to zeroes  */

/*  If we initialize the first element with any number other numbers in the array will be zeroes  */

#include<bits/stdc++.h>
using namespace std;

array<int, 10> arr;

int main(){
    array<int, 10> arr_1;

    // Printing the global array
    for(int i=0; i<10; i++){
        cout<< arr[i] << " ";
    }
    cout<<"\n";
    // Output:
    // 0 0 0 0 0 0 0 0 0 0 

    // Printing the local array
    for(int i=0; i<10; i++){
        cout<< arr_1[i] << " ";
    }
    cout<<"\n";
    // Output:
    // -1663042624 98 2095127112 32759 -802929584 559 -1663042384 1 213850828 142645788 

    // Printing a local array where we intialize half array & leave other half
    array<int, 10> arr_2 = {1,2,3};
    for(int i=0; i<10; i++){
        cout<< arr_2[i] << " ";
    }
    cout<<"\n";
    // Output:
    // 1 2 3 0 0 0 0 0 0 0

    // Proving that initialzing the first element with any value makes all the values of the array zero
    array<int, 10> arr_3 = {0};
    for(int i=0; i<10; i++){
        cout<< arr_3[i] << " ";
    }
    cout<<"\n";
    // Output:
    // 0 0 0 0 0 0 0 0 0 0
}
