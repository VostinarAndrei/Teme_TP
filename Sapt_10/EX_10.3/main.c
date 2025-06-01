#include <stdio.h>

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int cifra_max(int n) {
    int last_digit,max_rest;
    if (n < 10) {
        return n;
    } else {
        last_digit = n % 10;
        max_rest = cifra_max(n / 10);
        return max(last_digit, max_rest);
    }
}

int main() {
    int n;
    printf("n= ");
    scanf("%d", &n);

    printf("cifra maxima: %d\n", cifra_max(n));
    return 0;
}
