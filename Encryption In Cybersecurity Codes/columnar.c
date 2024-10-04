#include <stdio.h>
#include <string.h>

void colEncr(char pt[], char key[], char ct[])
{
    int len = strlen(pt);
    int keyLen = strlen(key);
    int rows = (len + keyLen - 1) / keyLen;
    char matrix[rows][keyLen];
    int k = 0, i, j;

    // Fill the matrix with plain text characters and pad with 'X'
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < keyLen; j++)
        {
            if (k < len)
            {
                matrix[i][j] = pt[k];
                k++;
            }


            else
                matrix[i][j] = 'X';  // Padding character
        }
    }

    k = 0;
    // Rearrange columns based on the key
    for (i = 0; i < keyLen; i++)
    {
        int col = key[i] - '1';  // Correctly map the key to the column index
        for (j = 0; j < rows; j++)
        {
            ct[k] = matrix[j][col];
            k++;
        }
    }
    ct[k] = '\0';
}

int main()
{
    char pt[100], key[10], ct[100];

    printf("Enter the plain text: ");
    scanf("%s",pt);

    printf("Enter the key (as a permutation of numbers, e.g., 31452): ");
    scanf("%s",key);

    colEncr(pt, key, ct);

    printf("Encrypted text: %s\n", ct);

    return 0;
}
