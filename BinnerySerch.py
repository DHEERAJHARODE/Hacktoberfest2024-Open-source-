#include<stdio.h>
#include<stdlib.h>

int main() {
    int r, c, i, j, k;

    // Input number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    // Dynamically allocate memory for matrices
    int **a = (int **)malloc(r * sizeof(int *));
    int **b = (int **)malloc(r * sizeof(int *));
    int **mul = (int **)malloc(r * sizeof(int *));
    
    for(i = 0; i < r; i++) {
        a[i] = (int *)malloc(c * sizeof(int));
        b[i] = (int *)malloc(c * sizeof(int));
        mul[i] = (int *)malloc(c * sizeof(int));
    }

    // Input elements for matrix A
    printf("Enter the elements of the first matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input elements for matrix B
    printf("Enter the elements of the second matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Initialize result matrix mul to zero
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            mul[i][j] = 0;
        }
    }

    // Matrix multiplication
    printf("Multiplication of the matrices:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            for(k = 0; k < c; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print the result matrix
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d\t", mul[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for(i = 0; i < r; i++) {
        free(a[i]);
        free(b[i]);
        free(mul[i]);
    }
    free(a);
    free(b);
    free(mul);

    return 0;
}
