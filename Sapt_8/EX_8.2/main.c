#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Cuvant {
    char text[16];
    int contor;
    struct Cuvant *pred;
    struct Cuvant *urm;
} Cuvant;


typedef struct {
    Cuvant *prim;
    Cuvant *ultim;
} Propozitie;


Cuvant *Cuvant_nou(const char *text)
{
    Cuvant *c = (Cuvant*)malloc(sizeof(Cuvant));
    if (!c) {
        printf("Memorie insuficienta!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text, text);
    c->contor = 1;
    c->pred = NULL;
    c->urm = NULL;
    return c;
}


void Propozitie_init(Propozitie *p)
{
    p->prim = NULL;
    p->ultim = NULL;
}


void Propozitie_adauga(Propozitie *p, Cuvant *c)
{
    c->pred = p->ultim;
    c->urm = NULL;
    if (p->ultim) {
        p->ultim->urm = c;
    } else {
        p->prim = c;
    }
    p->ultim = c;
}


Cuvant *Propozitie_cauta(Propozitie *p, const char *text)
{
    Cuvant *c = p->prim;
    while (c != NULL) {
        if (strcmp(c->text, text) == 0) {
            return c;
        }
        c = c->urm;
    }
    return NULL;
}


void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *c = p->prim;
    while (c != NULL) {
        Cuvant *urm = c->urm;
        free(c);
        c = urm;
    }
    Propozitie_init(p);
}


void to_lowercase_simple(char *s)
{
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s = *s - 'A' + 'a';
        }
        s++;
    }
}


void Propozitie_insera_inainte(Propozitie *p, Cuvant *c_nou, const char *succesor_text)
{
    Cuvant *succ = Propozitie_cauta(p, succesor_text);

    if (succ) {
        c_nou->urm = succ;
        c_nou->pred = succ->pred;
        if (succ->pred) {

            succ->pred->urm = c_nou;
        } else {
            p->prim = c_nou;
        }
        succ->pred = c_nou;
    } else {

        Propozitie_adauga(p, c_nou);
    }
}

int main()
{
    Propozitie p;
    int optiune;
    char text[16];

    Propozitie_init(&p);

    do {
        printf("\nMeniu:\n");
        printf("1 - Introdu propozitie noua\n");
        printf("2 - Afiseaza propozitia si frecventa cuvintelor\n");
        printf("3 - Sterge un cuvant\n");
        printf("4 - Insereaza un cuvant inaintea unui succesor\n");
        printf("5 - Iesire\n");
        printf("Optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                Propozitie_elibereaza(&p);
                printf("Introdu cuvinte (termina cu .):\n");
                while (1) {
                    scanf("%15s", text);
                    if (strcmp(text, ".") == 0) break;

                    to_lowercase_simple(text);

                    Cuvant *gasit = Propozitie_cauta(&p, text);
                    if (gasit) {
                        gasit->contor++;
                    } else {
                        Cuvant *nou = Cuvant_nou(text);
                        Propozitie_adauga(&p, nou);
                    }
                }
                break;

            case 2:
                if (p.prim == NULL) {
                    printf("Propozitia este goala.\n");
                } else {
                    Cuvant *c = p.prim;
                    while (c != NULL) {
                        printf("%s(%d) ", c->text, c->contor);
                        c = c->urm;
                    }
                    printf(".\n");
                }
                break;

            case 3: {
                printf("Cuvant de sters: ");
                scanf("%15s", text);
                to_lowercase_simple(text);
                Cuvant *de_sters = Propozitie_cauta(&p, text);
                if (de_sters) {

                    if (de_sters->pred) {
                        de_sters->pred->urm = de_sters->urm;
                    } else {
                        p.prim = de_sters->urm;
                    }
                    if (de_sters->urm) {
                        de_sters->urm->pred = de_sters->pred;
                    } else {
                        p.ultim = de_sters->pred;
                    }
                    free(de_sters);
                    printf("Cuvantul \"%s\" a fost sters.\n", text);
                } else {
                    printf("Cuvantul \"%s\" nu exista in propozitie.\n", text);
                }
                break;
            }

            case 4: {
                char cuv_insert[16], cuv_succ[16];
                printf("Cuvant de inserat: ");
                scanf("%15s", cuv_insert);
                to_lowercase_simple(cuv_insert);

                printf("Succesorul: ");
                scanf("%15s", cuv_succ);
                to_lowercase_simple(cuv_succ);

                Cuvant *gasit = Propozitie_cauta(&p, cuv_insert);
                if (gasit) {
                    gasit->contor++;
                    printf("Cuvantul \"%s\" exista deja, s-a incrementat contorul.\n", cuv_insert);
                } else {
                    Cuvant *nou = Cuvant_nou(cuv_insert);
                    Propozitie_insera_inainte(&p, nou, cuv_succ);
                    printf("Cuvantul \"%s\" a fost inserat.\n", cuv_insert);
                }
                break;
            }

            case 5:
                printf("La revedere!\n");
                break;

            default:
                printf("Optiune invalida!\n");
        }

    } while (optiune != 5);

    Propozitie_elibereaza(&p);
    return 0;
}
