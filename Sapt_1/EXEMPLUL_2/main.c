#include <stdio.h>
int main()
{
    float a[10][10];
    int i, j, m, n;
    printf("m=");
    scanf("%d", &m);
    printf("n=");
    scanf("%d", &n);
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            a[i][j] = (i + j) / 2.0;
        }
    }
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf("%5.2g", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}