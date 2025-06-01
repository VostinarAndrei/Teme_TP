#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
    int val;
    struct nod *urm;
} nod;


nod* nou(int val) {
    nod* p = (nod*)malloc(sizeof(nod));
    p->val = val;
    p->urm = NULL;
    return p;
}


void adaugaSfarsit(nod **ultim, int val) {
    nod* p = nou(val);
    if (*ultim == NULL) {
        p->urm = p;
        *ultim = p;
    } else {
        p->urm = (*ultim)->urm;
        (*ultim)->urm = p;
        *ultim = p;
    }
}


void afisare(nod *ultim) {
    if (ultim == NULL) {
        printf("Lista este goala.\n");
        return;
    }
    nod *curent = ultim->urm;
    do {
        printf("%d ", curent->val);
        curent = curent->urm;
    } while (curent != ultim->urm);
    printf("\n");
}


void sterge(nod **ultim, int val) {
    if (*ultim == NULL) return;

    nod *curent = (*ultim)->urm;
    nod *precedent = *ultim;

    do {
        if (curent->val == val) {
            if (curent == precedent) {
                free(curent);
                *ultim = NULL;
                return;
            }
            precedent->urm = curent->urm;
            if (curent == *ultim) {
                *ultim = precedent;
            }
            free(curent);
            return;
        }

        precedent = curent;
        curent = curent->urm;

    } while (curent != (*ultim)->urm);
}

int main() {
    nod *ultim = NULL;

    adaugaSfarsit(&ultim, 10);
    adaugaSfarsit(&ultim, 20);
    adaugaSfarsit(&ultim, 30);
    adaugaSfarsit(&ultim, 40);

    printf("Lista initiala: ");
    afisare(ultim);

    sterge(&ultim, 30);
    printf("Dupa stergerea lui 30: ");
    afisare(ultim);

    sterge(&ultim, 10);
    printf("Dupa stergerea lui 10 (primul element): ");
    afisare(ultim);

    sterge(&ultim, 40);
    printf("Dupa stergerea lui 40 (ultimul element): ");
    afisare(ultim);

    sterge(&ultim, 20);
    printf("Dupa stergerea lui 20 (ultimul element ramas): ");
    afisare(ultim);

    return 0;
}
