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


elem *inversare(elem *lista) {
    elem *prev = NULL;
    elem *cur = lista;
    elem *next;

    while (cur != NULL) {
        next = cur->urm;
        cur->urm = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int main() {

    elem *lista = nou(1, nou(2, nou(3, NULL)));

    printf("Lista initiala: ");
    afisare(lista);

    lista = inversare(lista);

    printf("Lista inversata: ");
    afisare(lista);

    eliberare(lista);
    return 0;
}
