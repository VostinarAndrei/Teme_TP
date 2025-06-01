#include <stdio.h>
#include <stdarg.h>


void absN(int n, ...)
{
    va_list a;
    va_start(a, n);

    for (int i = 0; i < n; i++) {
        float *p = va_arg(a, float*);
        if (*p < 0)
            *p = -*p;
    }

    va_end(a);
}

int main()
{
    float x = -3.5, y = 2.1, z = -7;

    printf("Inainte: x = %g, y = %g, z = %g\n", x, y, z);

    absN(3, &x, &y, &z);

    printf("Dupa:    x = %g, y = %g, z = %g\n", x, y, z);

    return 0;
}
