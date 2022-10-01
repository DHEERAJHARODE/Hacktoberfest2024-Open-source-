#include <iostream>
using namespace std;
 
int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;
     
    int sum = 0;
    int digit;
    int temp = n;
    while (temp > 0) {
        digit = temp % 10;
        sum = sum + (digit * digit * digit);
        temp = temp / 10;
    }
     
    if (sum == n) {
        cout << "An Armstrong Number." << endl;
    } else {
        cout << "Not an Armstrong Number." << endl;
    }
}
