#include <stdio.h>
#include <stdlib.h>

void stelute(int n)
{
    while(n--)printf("*");
}
void spatii(int n)
{
    while(n--)printf(" ");
}
int main(int argc, char *argv[])
{
    int i, n;
    for (i = 1; i < argc; i++) {
        n = atoi(argv[i]);
        if (i % 2 == 1)
            stelute(n);
        else
            spatii(n);
    }
    printf("\n");
    return 0;
}