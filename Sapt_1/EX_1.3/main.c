#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, i, j, val = 1;
    int **a;

    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);

    a = (int**)malloc(m * sizeof(int*));
    if (a == NULL) {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < m; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
        if (a[i] == NULL) {
            for (i--; i >= 0; i--) free(a[i]);
            free(a);
            printf("Memorie insuficienta\n");
            exit(EXIT_FAILURE);
        }}

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = val;
            val++;}
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
