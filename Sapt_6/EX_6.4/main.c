#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int crescator(int n, char tip, ...)
{
    va_list a;
    va_start(a, tip);

    if (n < 2) {
        va_end(a);
        return 1;
    }

    if (tip == 'd') {
        int prev = va_arg(a, int);
        for (int i = 1; i < n; i++) {
            int cur = va_arg(a, int);
            if (cur <= prev) {
                va_end(a);
                return 0;
            }
            prev = cur;
        }
    } else if (tip == 'f') {
        double prev = va_arg(a, double);
        for (int i = 1; i < n; i++) {
            double cur = va_arg(a, double);
            if (cur <= prev) {
                va_end(a);
                return 0;
            }
            prev = cur;
        }
    } else {
        va_end(a);
        return 0;
    }

    va_end(a);
    return 1;
}

int main()
{
    printf("%d\n", crescator(3, 'd', -1, 7, 9));
    printf("%d\n", crescator(3, 'd', 5, 5, 10));       
    printf("%d\n", crescator(4, 'f', 1.2, 2.5, 3.6, 4.7)); 
    printf("%d\n", crescator(2, 'f', 2.5, 1.5));       
    return 0;
}
