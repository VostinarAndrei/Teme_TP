#include <stdio.h>

int suma_cifrelor(int n) {
    if (n < 10)
        return n;
    else
        return (n % 10) + suma_cifrelor(n / 10);
}

int main() {
    int n;
    printf("n= ");
    scanf("%d", &n);

    printf("s=%d\n", suma_cifrelor(n));
    return 0;
}
