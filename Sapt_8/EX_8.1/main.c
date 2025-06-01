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

void to_lowercase(char *s)
{
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s = *s - 'A' + 'a';
        }
        s++;
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
        printf("3 - Iesire\n");
        printf("Optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:

                Propozitie_elibereaza(&p);
                printf("Introdu cuvinte (termina cu .):\n");
                while (1) {
                    scanf("%15s", text);

                    if (strcmp(text, ".") == 0) {
                        break;
                    }

                    to_lowercase(text);

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

            case 3:
                printf("La revedere!\n");
                break;

            default:
                printf("Optiune invalida!\n");
        }

    } while (optiune != 3);

    Propozitie_elibereaza(&p);
    return 0;
}
