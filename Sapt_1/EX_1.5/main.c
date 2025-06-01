#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    int **a;
    int *sumeL;
    int *sumeC;

    printf("n = ");
    scanf("%d", &n);


    a = (int**)malloc(n * sizeof(int*));
    if (a == NULL) {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
        if (a[i] == NULL) {
            for (i--; i >= 0; i--) free(a[i]);
            free(a);
            printf("Memorie insuficienta\n");
            exit(EXIT_FAILURE);
        }
    }


    sumeL = (int*)malloc(n * sizeof(int));
    sumeC = (int*)malloc(n * sizeof(int));
    if (sumeL == NULL || sumeC == NULL) {
        printf("Memorie insuficienta\n");
        for (i = 0; i < n; i++) free(a[i]);
        free(a);
        if (sumeL) free(sumeL);
        if (sumeC) free(sumeC);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++) {
        sumeL[i] = 0;
        sumeC[i] = 0;
    }


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sumeL[i] += a[i][j];
            sumeC[j] += a[i][j];
        }
    }

    printf("Sumele pe linii: ");
    for (i = 0; i < n; i++)
        printf("%d ", sumeL[i]);
    printf("\n");


    printf("Sumele pe coloane: ");
    for (i = 0; i < n; i++)
        printf("%d ", sumeC[i]);
    printf("\n");

    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(sumeL);
    free(sumeC);

    return 0;
}
