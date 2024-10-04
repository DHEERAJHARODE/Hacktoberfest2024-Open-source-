#include <stdio.h>
#include <math.h>

long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long p, g, a, b;
    long long A, B, sharedKeyA, sharedKeyB;

    printf("Enter a large prime number (p): ");
    scanf("%lld", &p);
    printf("Enter a primitive root modulo p (g): ");
    scanf("%lld", &g);
    printf("Enter the private key of the first party (a): ");
    scanf("%lld", &a);
    printf("Enter the private key of the second party (b): ");
    scanf("%lld", &b);

    A = powerMod(g, a, p);
    B = powerMod(g, b, p);

    sharedKeyA = powerMod(B, a, p);
    sharedKeyB = powerMod(A, b, p);

    printf("Public Key of First Party (A): %lld\n", A);
    printf("Public Key of Second Party (B): %lld\n", B);
    printf("Shared Secret Key computed by First Party: %lld\n", sharedKeyA);
    printf("Shared Secret Key computed by Second Party: %lld\n", sharedKeyB);

    return 0;
}
