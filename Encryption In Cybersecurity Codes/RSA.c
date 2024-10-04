#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int mod_pow(int base, int ex, int m)
{
    int result = 1;
    base = base % m;
    while (ex > 0)
    {
        if (ex % 2 == 1)
        {
            result = (result * base) % m;
        }
        ex = ex >> 1;
        base = (base * base) % m;
    }
    return result;
}
int mod_inverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
    {
        if ((a*x) % m == 1)
        {
            return x;
        }
    }
    return 0;
}
int main()
{
    int p = 61;
    int q = 53;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 17;
    int d = mod_inverse(e, phi);
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);
    int message;
    printf("Enter a message to encrypt: ");
    scanf("%d", &message);
    int ct = mod_pow(message, e, n);
    printf("Encrypted message: %d\n", ct);
    int decrypted_message = mod_pow(ct, d, n);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}
