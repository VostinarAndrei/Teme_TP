#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    int n;
    struct elem *urm;
} elem;

elem *nou(int n, elem *urm) {
    elem *e = (elem*)malloc(sizeof(elem));
    if (!e) {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    e->n = n;
    e->urm = urm;
    return e;
}

void afisare(elem *lista) {
    for (; lista; lista = lista->urm) {
        printf("%d ", lista->n);
    }
    putchar('\n');
}

void eliberare(elem *lista) {
    elem *p;
    while (lista) {
        p = lista->urm;
        free(lista);
        lista = p;
    }
}


int exista(elem *lista, int val) {
    for (; lista; lista = lista->urm) {
        if (lista->n == val)
            return 1;
    }
    return 0;
}


elem *adaugaSfarsit(elem *lista, int val) {
    if (!lista) return nou(val, NULL);
    elem *p = lista;
    while (p->urm) p = p->urm;
    p->urm = nou(val, NULL);
    return lista;
}


elem *reuniune(elem *l1, elem *l2) {
    elem *rezultat = NULL;

    for (elem *p = l1; p != NULL; p = p->urm) {
        if (!exista(rezultat, p->n)) {
            rezultat = adaugaSfarsit(rezultat, p->n);
        }
    }
    for (elem *p = l2; p != NULL; p = p->urm) {
        if (!exista(rezultat, p->n)) {
            rezultat = adaugaSfarsit(rezultat, p->n);
        }
    }
    return rezultat;
}

int main() {
    elem *l1 = nou(1, nou(2, nou(3, nou(2, NULL))));
    elem *l2 = nou(3, nou(4, nou(5, NULL)));

    printf("Lista 1: ");
    afisare(l1);

    printf("Lista 2: ");
    afisare(l2);

    elem *rez = reuniune(l1, l2);
    printf("Reuniune: ");
    afisare(rez);

    eliberare(l1);
    eliberare(l2);
    eliberare(rez);

    return 0;
}
