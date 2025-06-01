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

Nod* stergeInceput(Nod* cap, int* val) {
    if (!cap)
        return NULL;
    *val = cap->info;
    Nod* aux = cap;
    cap = cap->next;
    free(aux);
    return cap;
}

Nod* permutaStanga(Nod* cap, int k) {
    for (int i = 0; i < k && cap; i++) {
        int val;
        cap = stergeInceput(cap, &val);
        cap = adaugaSfarsit(cap, val);
    }
    return cap;
}

int main() {
    FILE* f = fopen("date.in", "r");
    if (!f) {
        perror("Eroare deschidere fisier");
        return 1;
    }
    int k, x;
    if (fscanf(f, "%d", &k) != 1) {
        fprintf(stderr, "Eroare la citirea lui k\n");
        return 1;
    }
    Nod* lista = NULL;
    while (fscanf(f, "%d", &x) == 1)
        lista = adaugaSfarsit(lista, x);

    fclose(f);
    lista = permutaStanga(lista, k);

    FILE* g = fopen("date.out", "w");
    if (!g) {
        perror("Eroare creare fisier de iesire");
        return 1;
    }

    Nod* p = lista;
    while (p) {
        fprintf(g, "%d ", p->info);
        p = p->next;
    }
    fprintf(g, "\n");

    fclose(g);
    eliberare(lista);
    return 0;
}
