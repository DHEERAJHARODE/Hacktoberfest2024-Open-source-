// C Program to check for prime number using
//  Simple Trial Division
#include <stdbool.h>
#include <stdio.h>

int main() {
    int n = 29;

    int cnt = 0;

    // If number is less than/equal to 1,
    // it is not prime
    if (n <= 1)
        printf("%d is NOT prime\n", n);
    else {

        // Check for divisors from 1 to n
        for (int i = 1; i <= n; i++) {

            // Check how many number is divisible
            // by n
            if (n % i == 0)
                cnt++;
        }

        // If n is divisible by more than 2 numbers
        // then it is not prime
        if (cnt > 2)
            printf("%d is NOT prime\n", n);

        // else it is prime
        else
            printf("%d is prime", n);
    }

    return 0;
}
