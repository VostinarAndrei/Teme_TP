#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    int **a;

    printf("n = ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Valoare invalida pentru n\n");
        return 1;
    }

    a = (int**)malloc(n * sizeof(int*));
    if (a == NULL) {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
        if (a[i] == NULL) {
            for (i--; i >= 0; i--)
                free(a[i]);
            free(a);
            printf("Memorie insuficienta\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i == j)
                a[i][j] = 1;
            else
                a[i][j] = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}
