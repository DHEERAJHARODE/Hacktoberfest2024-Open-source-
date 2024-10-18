// C++ program to check if a number is Harshad  
// Number or not.  
#include <bits/stdc++.h>  
using namespace std;  
    
// function to check Harshad Number  
bool checkHarshad(int n)  
{  
    // calculate sum of digits  
    int sum = 0;  
    for (int temp = n; temp > 0; temp /= 10)  
        sum += temp % 10;  
    
    // Return true if sum of digits is multiple  
    // of n  
    return (n % sum == 0);  
}  
    
// driver program to check above function  
int main()  
{  
    checkHarshad(12) ? cout << "Yes\n" : cout << "No\n";  
    checkHarshad(15) ? cout << "Yes\n" : cout << "No\n";  
    
    return 0;  
}
