#include "iostream"
using namespace std;
int main() {
    
    // 'n' is the number we want to check is prime or not.
    int n;
    cin >> n;
    if (n < 2) {
        cout << "false" << endl;
        return 0;
    }
    bool isPrime = true;
    
    // Iterate over all the possible smaller divisor of n.
    for (int i = 2;i * i <= n;++i) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    cout << (isPrime ? "true" : "false") << endl;
    return 0;
}
