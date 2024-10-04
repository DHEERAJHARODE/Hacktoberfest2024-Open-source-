#include <stdio.h>
#include <math.h>
#include <string.h>

long p, q, n, t, e, d;
char msg[100];

int prime(long);
void computeKeys();
long modExp(long, long, long);
void encrypt();
void decrypt();

int main() {
    printf("Enter prime p: ");
    scanf("%ld", &p);
    printf("Enter prime q: ");
    scanf("%ld", &q);
    printf("Enter message: ");
    scanf(" %[^\n]s", msg);

    if (!prime(p) || !prime(q)) {
        printf("Invalid primes.\n");
        return 1;
    }

    n = p * q;
    t = (p - 1) * (q - 1);
    computeKeys();
    encrypt();
    decrypt();
    return 0;
}

int prime(long num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return 0;
    return 1;
}

void computeKeys() {
    e = 2;
    while (e < t && t % e == 0) e++;
    d = 1;
    while ((d * e) % t != 1) d++;
}

long modExp(long base, long exp, long mod) {
    long result = 1;
    for (int i = 0; i < exp; i++)
        result = (result * base) % mod;
    return result;
}

void encrypt() {
    printf("Encrypted: ");
    for (int i = 0; msg[i]; i++)
        printf("%c", modExp(msg[i], e, n));
    printf("\n");
}

void decrypt() {
    printf("Decrypted: ");
    for (int i = 0; msg[i]; i++)
        printf("%c", modExp(msg[i], d, n));
    printf("\n");
}
