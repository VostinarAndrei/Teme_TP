#include <stdio.h>

int fib(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("n mare (ex: 20): ");
    scanf("%d", &n);

    int Fn = fib(n);
    int Fn_plus_1 = fib(n + 1);

    double raport = (double)Fn_plus_1 / Fn;

    printf("F(%d) = %d\n", n, Fn);
    printf("F(%d) = %d\n", n + 1, Fn_plus_1);
    printf("Raportul F(%d)/F(%d) = %.15f\n", n + 1, n, raport);

    return 0;
}
