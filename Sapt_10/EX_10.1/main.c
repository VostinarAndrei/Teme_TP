#include <stdio.h>

int cmmdc(int a, int b) {
    if (b == 0)
        return a;
    else
        return cmmdc(b, a % b);
}

int main() {
    int a, b;
    printf("Introduceti doua numere: ");
    scanf("%d %d", &a, &b);

    printf("cmmdc = %d\n", a, b, cmmdc(a, b));
    return 0;
}
