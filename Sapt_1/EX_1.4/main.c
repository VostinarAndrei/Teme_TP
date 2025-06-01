#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, temp;
    int **a;

    printf("n = ");
    scanf("%d", &n);

    a = (int**)malloc(n * sizeof(int*));
    if (a == NULL) {
        printf("memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
        if (a[i] == NULL) {
            for (i--; i >= 0; i--)
                free(a[i]);
            free(a);
            printf("memorie insuficienta\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++) {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
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
