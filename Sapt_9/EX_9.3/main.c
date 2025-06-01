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

void insereazaDupaPare(Nod* cap) {
    while (cap) {
        if (cap->info % 2 == 0) {
            Nod* p = nou(cap->info / 2);
            p->next = cap->next;
            cap->next = p;
            cap = p->next;
        } else {
            cap = cap->next;
        }
    }
}

int main() {
    Nod* lista = NULL;
    int x;

    printf("Introduceti valori intregi, terminati cu 0:\n");
    while (scanf("%d", &x) == 1 && x != 0)
        lista = adaugaSfarsit(lista, x);

    insereazaDupaPare(lista);

    printf("Lista dupa inserare:\n");
    afisare(lista);

    eliberare(lista);
    return 0;
}
