#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produs {
    char nume[50];
    float pret;
    struct Produs *urm;
} Produs;

typedef struct Categorie {
    char nume[50];
    Produs *lista_produse;
    struct Categorie *urm;
} Categorie;


Categorie* adaugaCategorie(Categorie *cap, const char *nume)
{
    Categorie *nou = (Categorie*)malloc(sizeof(Categorie));
    if(!nou){
        printf("Memorie insuficienta!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nou->nume, nume);
    nou->lista_produse = NULL;
    nou->urm = NULL;

    if (!cap) return nou;


    Categorie *p = cap;
    while (p->urm) p = p->urm;
    p->urm = nou;

    return cap;
}


Categorie* cautaCategorie(Categorie *cap, const char *nume)
{
    Categorie *p = cap;
    while (p) {
        if (strcmp(p->nume, nume) == 0)
            return p;
        p = p->urm;
    }
    return NULL;
}


void adaugaProdus(Categorie *cat, const char *nume_produs, float pret)
{
    Produs *nou = (Produs*)malloc(sizeof(Produs));
    if(!nou){
        printf("Memorie insuficienta!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nou->nume, nume_produs);
    nou->pret = pret;
    nou->urm = NULL;

    if (!cat->lista_produse) {
        cat->lista_produse = nou;
    } else {
        Produs *p = cat->lista_produse;
        while (p->urm) p = p->urm;
        p->urm = nou;
    }
}


void afiseazaCategorii(Categorie *cap)
{
    if (!cap) {
        printf("Nu exista categorii.\n");
        return;
    }
    printf("Categorii:\n");
    Categorie *p = cap;
    while (p) {
        printf("- %s\n", p->nume);
        p = p->urm;
    }
}


void afiseazaProduse(Categorie *cat)
{
    if (!cat) {
        printf("Categoria nu exista.\n");
        return;
    }
    if (!cat->lista_produse) {
        printf("Categoria \"%s\" nu are produse.\n", cat->nume);
        return;
    }
    printf("Produse in categoria \"%s\":\n", cat->nume);
    Produs *p = cat->lista_produse;
    while (p) {
        printf("- %s: %.2f\n", p->nume, p->pret);
        p = p->urm;
    }
}


void elibereazaProduse(Produs *cap)
{
    Produs *p = cap;
    while (p) {
        Produs *urm = p->urm;
        free(p);
        p = urm;
    }
}


void elibereazaCategorii(Categorie *cap)
{
    Categorie *p = cap;
    while (p) {
        Categorie *urm = p->urm;
        elibereazaProduse(p->lista_produse);
        free(p);
        p = urm;
    }
}

int main()
{
    Categorie *categorii = NULL;
    int optiune;

    do {
        printf("\nMeniu:\n");
        printf("1 - Adauga categorie\n");
        printf("2 - Adauga produs\n");
        printf("3 - Afiseaza categorii\n");
        printf("4 - Afiseaza produse din categorie\n");
        printf("5 - Iesire\n");
        printf("Optiune: ");
        scanf("%d", &optiune);
        getchar();

        if (optiune == 1) {
            char nume[50];
            printf("Numele categoriei: ");
            fgets(nume, sizeof(nume), stdin);
            nume[strcspn(nume, "\n")] = 0;

            if (cautaCategorie(categorii, nume)) {
                printf("Categoria exista deja!\n");
            } else {
                categorii = adaugaCategorie(categorii, nume);
                printf("Categoria adaugata cu succes.\n");
            }

        } else if (optiune == 2) {
            char nume_cat[50];
            printf("Categoria in care adaugi produsul: ");
            fgets(nume_cat, sizeof(nume_cat), stdin);
            nume_cat[strcspn(nume_cat, "\n")] = 0;

            Categorie *cat = cautaCategorie(categorii, nume_cat);
            if (!cat) {
                printf("Categoria nu exista!\n");
                continue;
            }

            char nume_prod[50];
            printf("Numele produsului: ");
            fgets(nume_prod, sizeof(nume_prod), stdin);
            nume_prod[strcspn(nume_prod, "\n")] = 0;

            float pret;
            printf("Pretul produsului: ");
            scanf("%f", &pret);
            getchar();

            adaugaProdus(cat, nume_prod, pret);
            printf("Produs adaugat cu succes.\n");

        } else if (optiune == 3) {
            afiseazaCategorii(categorii);

        } else if (optiune == 4) {
            char nume_cat[50];
            printf("Categoria pentru afisare produse: ");
            fgets(nume_cat, sizeof(nume_cat), stdin);
            nume_cat[strcspn(nume_cat, "\n")] = 0;

            Categorie *cat = cautaCategorie(categorii, nume_cat);
            afiseazaProduse(cat);

        } else if (optiune == 5) {
            printf("La revedere!\n");
            elibereazaCategorii(categorii);
            break;

        } else {
            printf("Optiune invalida!\n");
        }

    } while (1);

    return 0;
}
