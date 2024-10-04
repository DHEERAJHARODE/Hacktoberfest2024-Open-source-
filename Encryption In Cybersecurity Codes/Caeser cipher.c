#include <stdio.h>
#include <ctype.h>
#include<string.h>

char enc(char ch, int key)
{
    if (isalpha(ch))
    {
        char b = islower(ch) ? 'a' : 'A';  // Added spaces around operators for readability
        ch = (ch - b + key) % 26 + b;      // Added spaces around operators for readability
    }
    return ch;
}

int main()  // Changed 'void main()' to 'int main()'
{
    char pt[100];
    int key, i;  // Added a space after the comma for readability

    printf("Enter the plain text: ");
    scanf("%s",pt);

    printf("Enter the key value: ");
    scanf("%d", &key);

    for (i = 0; pt[i] != '\0'; i++)
        pt[i] = enc(pt[i], key);

    printf("Encrypted text: %s\n", pt);  // Replaced non-ASCII space with a regular space

    return 0;  // Added return 0 to the main function
}
