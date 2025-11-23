#include <stdio.h>

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int sum[3][3], sub[3][3], prod[3][3], trans[3][3];
    int i, j, k;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            sum[i][j] = A[i][j] + B[i][j];

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            sub[i][j] = A[i][j] - B[i][j];

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            prod[i][j] = 0;
            for (k = 0; k < 3; k++)
                prod[i][j] += A[i][k] * B[k][j];
        }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            trans[j][i] = A[i][j];

    printf("Sum:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    printf("Subtraction:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", sub[i][j]);
        printf("\n");
    }

    printf("Product:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", prod[i][j]);
        printf("\n");
    }

    printf("Transpose of A:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", trans[i][j]);
        printf("\n");
    }

    return 0;
}
