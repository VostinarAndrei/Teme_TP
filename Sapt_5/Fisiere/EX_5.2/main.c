#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    printf("Introduceti m si n: ");
    scanf("%d %d", &m, &n);

    int *a = malloc(m * n * sizeof(int));
    if (a == NULL) {
        printf("Memorie insuficienta!\n");
        return 1;
    }

    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i * n + j]);

    FILE *f = fopen("matrice.txt", "w");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului!\n");
        free(a);
        return 1;
    }

    fprintf(f, "Matricea originala:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(f, "%d ", a[i * n + j]);
        }
        fprintf(f, "\n");
    }

    fprintf(f, "\nTranspusa:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            fprintf(f, "%d ", a[i * n + j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
    free(a);

    printf("Datele au fost scrise in matrice.txt\n");
    return 0;
}
