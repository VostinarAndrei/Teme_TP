#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nume[30];
    char functie[30];
    float salariu;
} Angajat;

Angajat *angajati = NULL;
int nAngajati = 0;

void citireSir(const char *text, char *dst, size_t max) {
    printf("%s: ", text);
    fgets(dst, max, stdin);
    dst[strcspn(dst, "\n")] = '\0';
}

int main() {
    int i, j, op;
    Angajat *v2;
    char buf[30];

    for (;;) {
        printf("1. Adaugare\n");
        printf("2. Stergere\n");
        printf("3. Listare\n");
        printf("4. Iesire\n");
        printf("Optiune: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                v2 = realloc(angajati, (nAngajati + 1) * sizeof(Angajat));
                if (!v2) {
                    printf("memorie insuficienta\n");
                    free(angajati);
                    exit(EXIT_FAILURE);
                }
                angajati = v2;
                getchar();
                citireSir("Nume", angajati[nAngajati].nume, 30);
                citireSir("Functie", angajati[nAngajati].functie, 30);
                printf("Salariu: ");
                scanf("%g", &angajati[nAngajati].salariu);
                nAngajati++;
                break;
            case 2:
                getchar();
                citireSir("Nume", buf, 30);
                for (i = 0; i < nAngajati; i++) {
                    if (!strcmp(buf, angajati[i].nume)) {
                        for (j = i; j < nAngajati - 1; j++)
                            angajati[j] = angajati[j + 1];
                        i--;
                        nAngajati--;
                    }
                }
                angajati = realloc(angajati, nAngajati * sizeof(Angajat));
                break;
            case 3:
                for (i = 0; i < nAngajati; i++)
                    printf("%s\t%s\t%g\n", angajati[i].nume, angajati[i].functie, angajati[i].salariu);
                break;
            case 4:
                free(angajati);
                return 0;
            default:
                printf("optiune necunoscuta\n");
        }
    }
}
