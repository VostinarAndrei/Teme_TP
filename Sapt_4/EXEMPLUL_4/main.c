#include <stdio.h>
#include <string.h>

typedef struct {
    char nume[100];
    float pret;
} Produs;

void reduce(Produs *p, float reducere) {
    p->pret *= 1 - reducere / 100;
}

int main() {
    int n, i;
    float r;
    Produs produse[50];

    printf("reducere: ");
    scanf("%f", &r);
    printf("n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        getchar();
        printf("nume %d: ", i);
        fgets(produse[i].nume, 100, stdin);
        produse[i].nume[strcspn(produse[i].nume, "\n")] = '\0';
        printf("pret %d: ", i);
        scanf("%g", &produse[i].pret);
    }

    for (i = 0; i < n; i++)
        reduce(&produse[i], r);

    for (i = 0; i < n; i++)
        printf("%s %g\n", produse[i].nume, produse[i].pret);

    return 0;
}
