#include <stdio.h>
int main()
{
    float a[10][10], suma;
    int i, j, m, n, k;
    printf("nr studenti=");
    scanf("%d", &m);
    printf("nr maxim note=");
    scanf("%d", &n);
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            a[i][j] = -1;
        }
    }
    for (i = 0; i < m; i++){
        printf("notele studentului %d\n", i);
        for (j = 0; j < n; j++){
            printf("nota: ");
            scanf("%g", &a[i][j]);
            if (a[i][j] == -1)break;
        }
    }
    for (i = 0; i < m; i++){
        k = 0;
        suma = 0;
        for (j = 0; j < n; j++){
            if (a[i][j] != -1){
                suma += a[i][j];
                k++;
            }else{
                break;
            }
        }
        if (k == 0){
            printf("studentul %d nu are note\n", i);
        }else{
            printf("studentul %d are media %g\n", i, suma / k);
        }
    }
    return 0;
}