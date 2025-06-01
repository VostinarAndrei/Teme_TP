#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINIE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Folosește: %s nume_fisier cuvant1 [cuvant2 ...]\n", argv[0]);
        return 1;
    }

    FILE *fisier = fopen(argv[1], "r");
    if (fisier == NULL) {
        printf("Nu pot deschide fisierul %s\n", argv[1]);
        return 1;
    }

    char linie[MAX_LINIE];


    while (fgets(linie, MAX_LINIE, fisier) != NULL) {
        int toate_cuvintele_gasite = 1;

        for (int i = 2; i < argc; i++) {
            if (strstr(linie, argv[i]) == NULL) {
                toate_cuvintele_gasite = 0;
                break;
            }
        }
        
        if (toate_cuvintele_gasite) {
            printf("%s", linie);
        }
    }

    fclose(fisier);
    return 0;
}
