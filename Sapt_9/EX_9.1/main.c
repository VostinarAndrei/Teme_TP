#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
    int info;
    struct nod* next;
} Nod;

Nod* nou(int val) {
    Nod* p = (Nod*)malloc(sizeof(Nod));
    if (!p) {
        perror("Eroare alocare");
        exit(EXIT_FAILURE);
    }
    p->info = val;
    p->next = NULL;
    return p;
}

Nod* adaugaSfarsit(Nod* cap, int val) {
    Nod* p = nou(val);
    if (!cap)
        return p;
    Nod* q = cap;
    while (q->next)
        q = q->next;
    q->next = p;
    return cap;
}

void afisare(Nod* cap) {
    for (; cap; cap = cap->next)
        printf("%d ", cap->info);
    printf("\n");
}

void eliberare(Nod* cap) {
    while (cap) {
        Nod* aux = cap;
        cap = cap->next;
        free(aux);
    }
}

Nod* concat(Nod* a, Nod* b) {
    if (!a) return b;
    Nod* q = a;
    while (q->next)
        q = q->next;
    q->next = b;
    return a;
}

int main() {
    FILE* f = fopen("date.txt", "r");
    if (!f) {
        perror("Eroare deschidere fisier");
        return 1;
    }

    Nod* pare = NULL;
    Nod* impare = NULL;
    int x;

    while (fscanf(f, "%d", &x) == 1) {
        if (x % 2 == 0)
            pare = adaugaSfarsit(pare, x);
        else
            impare = adaugaSfarsit(impare, x);
    }

    fclose(f);
    pare = concat(pare, impare);

    printf("Lista combinata (pare + impare):\n");
    afisare(pare);

    eliberare(pare);

    return 0;
}
