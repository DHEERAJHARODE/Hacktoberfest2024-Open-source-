#include<stdio.h>

int check(int x, int y) {
    return (x % y == 0) ? 0 : (y * ((x / y) + 1)) - x;
}

int main() {
    int l1, i, j, d, l2;

    printf("\nEnter the length of the key: ");
    scanf("%d", &l1);
    int sequence[l1], order[l1];

    printf("\nEnter the sequence key: ");
    for (i = 0; i < l1; ++i) scanf("%d", &sequence[i]);

    for (i = 1; i <= l1; ++i)
        for (j = 0; j < l1; ++j)
            if (sequence[j] == i) order[i-1] = j;

    printf("\nEnter the depth: ");
    scanf("%d", &d);

    printf("\nEnter the length of String without spaces: ");
    scanf("%d", &l2);
    int temp1 = check(l2, l1);
    int r = (l2 + temp1) / l1;

    char p[l2 + temp1], p1[r][l1];

    if (temp1 > 0)
        printf("\nYou need to enter %d bogus characters. Enter total %d characters: ", temp1, l2 + temp1);
    else
        printf("\nEnter the string: ");

    for (i = 0; i < l2 + temp1; ++i) scanf(" %c", &p[i]);

    while (d-- > 0) {
        int count = 0;
        for (i = 0; i < r; ++i)
            for (j = 0; j < l1; ++j)
                p1[i][j] = p[count++];

        for (i = 0; i < r; ++i) {
            for (j = 0; j < l1; ++j) printf("%c ", p1[i][j]);
            printf("\n");
        }

        count = 0;
        for (i = 0; i < l1; ++i)
            for (j = 0; j < r; ++j)
                p[count++] = p1[j][order[i]];

        for (i = 0; i < l2 + temp1; ++i) printf("%c ", p[i]);
        printf("\n");
    }
}



/* OUTPUT
[prat@localhost Desktop]$ gcc transposition.c
[prat@localhost Desktop]$ ./a.out

Enter the length of the key. 7

Enter the sequence key. 4 3 1 2 5 6 7

Enter the depth. 2

Enter the length of String without spaces . 23

You need to enter 5 bogus characters.So enter total 28 characters. attackpostponeduntiltwoamxyz



a t t a c k p
o s t p o n e
d u n t i l t
w o a m x y z

t t n a a p t m t s u o a o d w c o i x k n l y p e t z


t t n a a p t
m t s u o a o
d w c o i x k
n l y p e t z

n s c y a u o p t t w l t m d n a o i e p a x t t o k z

*/
