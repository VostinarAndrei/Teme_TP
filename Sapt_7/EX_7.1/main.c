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


typedef struct {
    elem *prim;
    elem *ultim;
} Lista;


void init(Lista *lista) {
    lista->prim = NULL;
    lista->ultim = NULL;
}


void adaugaSfarsit(Lista *lista, int n) {
    elem *e = nou(n, NULL);
    if (lista->ultim) {
        lista->ultim->urm = e;
    } else {
        lista->prim = e;
    }
    lista->ultim = e;
}


void afisare(Lista *lista) {
    elem *crt;
    for (crt = lista->prim; crt; crt = crt->urm) {
        printf("%d ", crt->n);
    }
    putchar('\n');
}


void eliberare(Lista *lista) {
    elem *p, *crt = lista->prim;
    while (crt) {
        p = crt->urm;
        free(crt);
        crt = p;
    }
    lista->prim = NULL;
    lista->ultim = NULL;
}


int listeEgale(Lista *l1, Lista *l2) {
    elem *e1 = l1->prim;
    elem *e2 = l2->prim;
    while (e1 && e2) {
        if (e1->n != e2->n) {
            return 0;
        }
        e1 = e1->urm;
        e2 = e2->urm;
    }
    return (e1 == NULL && e2 == NULL);
}


int main() {
    Lista l1, l2;
    init(&l1);
    init(&l2);

    adaugaSfarsit(&l1, 10);
    adaugaSfarsit(&l1, 20);
    adaugaSfarsit(&l1, 30);

    adaugaSfarsit(&l2, 10);
    adaugaSfarsit(&l2, 20);
    adaugaSfarsit(&l2, 30);

    printf("Lista 1: ");
    afisare(&l1);
    printf("Lista 2: ");
    afisare(&l2);

    if (listeEgale(&l1, &l2)) {
        printf("Listele sunt identice.\n");
    } else {
        printf("Listele sunt diferite.\n");
    }

    eliberare(&l1);
    eliberare(&l2);
    return 0;
}
