#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


float *allocVec(int n, ...)
{
    if (n <= 0) return NULL;

    float *v = malloc(n * sizeof(float));
    if (v == NULL) {
        printf("Eroare la alocare memorie.\n");
        exit(1);
    }

    va_list a;
    va_start(a, n);
    for (int i = 0; i < n; i++) {
        v[i] = (float)va_arg(a, double);
    }
    va_end(a);

    return v;
}


void afisare(float *v, int n)
{
    for (int i = 0; i < n; i++)
        printf("%g ", v[i]);
    printf("\n");
}

int main()
{
    float *v;
    int n = 4;
    v = allocVec(n, 1.5, -3, 7, 0);

    printf("Vectorul este: ");
    afisare(v, n);

    free(v);
    return 0;
}
