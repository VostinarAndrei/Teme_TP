#include <stdio.h>
int main()
{
    int a[10][10];
    int i, j, m, n;
    printf("m=");
    scanf("%d", &m);
    printf("n=");
    scanf("%d", &n);
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    int toate=1;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++)
            if (a[i][j] < 0){
                toate=0;
                break;
            }
        if (!toate){
             break;
        }
    }
    if (toate){
        printf("matricea are toate elementele pozitive");
    }else{
        printf("matricea are si elemente negative");
    }
    return 0;
}