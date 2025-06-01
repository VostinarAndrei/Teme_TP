#include <stdio.h>

int main() {
    int m, n, i, j;
    int a[10][10];

    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i > j)
                a[i][j] = i;
            else
                a[i][j] = j;
        }}

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
