#include <stdio.h>

int main() {
    int n, i, j;
    int a[10][10];
    int ok = 1;
    printf("n = ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j && a[i][j] != 1) {
                ok = 0;
            }
            if (i != j && a[i][j] != 0) {
                ok = 0;
            }
        }
    }

    if (ok == 1) {
        printf("DA\n");
    } else {
        printf("NU\n");
    }

    return 0;
}
