// lower_bound()
// upper_bound()
#include<bits/stdc++.h>
using namespace std;

void lb_ub(){
    // upper_bound
    // will return an iterator poiting to the first element greater than x
    // lower_bound
    // will return an iterator pointing to the first element not less than x
    int arr[] = {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12};
    cout<<"\nElements: 1 5 7 7 8 10 10 10 11 11 12\n"
        <<  "Indexe's: 0 1 2 3 4 05 06 07 08 09 10 11\n";
    cout<< "Lower Bound of 7 is: " << lower_bound(arr, arr+11, 7) - arr << "\n"
        << "Upper Bound of 7 is: " << upper_bound(arr, arr+11, 7) - arr << "\n";
}

// to see if an element exists or not and if yes find its index
void ques1(){
    int x = 10;
    int arr[] = {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12};
    if(binary_search(arr, arr+11, x)){
        cout << x << " is present at index " << lower_bound(arr, arr+11, x) - arr << endl;
    } else {
        cout << "Element not found :(" << endl;
    }
}

// above same question just new implementation
void ques2(){
    int x = 12;
    int arr[] = {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12};
    int index = lower_bound(arr, arr+11, x) - arr;
    if(index != 11 && arr[index] == x){
        cout << x << " found at index " << index;
    } else {
        cout << "Element not found :(" << endl;
    }
}

// to find the last occurence of x
void ques3(){
    int x = 9;
    int arr[] = {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12};
    int ub = upper_bound(arr, arr+11, x) - arr;
    ub--;
    if(ub>=0 && arr[ub] == x){
        cout << x << " found at index " << ub;
    } else {
        cout << "Couldnt find the element";
    }
}

// to find the no. of occurences of a element
void ques4(){
    int x = 9;
    int arr[] = {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12};
    int ub = upper_bound(arr, arr+11, x) - arr;
    int lb = lower_bound(arr, arr+11, x) - arr;
    int noc = ub - lb;
    cout << "No. of occurences of " << x << " are " << noc;
}

int main(){
    cout << "Enter x: ";
    int x;
    cin >> x;
    switch(x){
    case 1:
        lb_ub();
        break;
    case 2:
        ques1();
        break;
    case 3:
        ques2();
        break;
    case 4:
        ques3();
        break;
    case 5:
        ques4();
        break;
    }
}
/*
value a a a b b b c c c
index 0 1 2 3 4 5 6 7 8
bound       l     u
*/