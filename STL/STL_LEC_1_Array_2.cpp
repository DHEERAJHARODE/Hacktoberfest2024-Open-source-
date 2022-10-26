/* 
array.fill method
<ArrayName>.fill(<value>)

Accessing elements using at
<ArrayName>.at(<index>)
*/ 

#include<bits/stdc++.h>
using namespace std;

int main(){
    array<int, 10> arr;

    // Before filling the array
    for(int i=0; i<10; i++){
        cout<< arr[i] << " ";
    }
    cout<<"\n";
    // Output:
    // 450756608 32758 0 2 782236016 23 450763352 32758 -1731603232 527 

    // Fill Method
    arr.fill(5);

    // After filling
    // Accessing elements using .at()
    for(int i=0; i<10; i++){
        cout<< arr.at(i) << " ";
    }
    cout<<"\n";
    // Output:
    // 5 5 5 5 5 5 5 5 5 5
}
