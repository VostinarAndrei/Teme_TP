#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *culori[6] = {"alb", "galben", "rosu", "verde", "albastru", "negru"};
int nr_culori = 6;

char steag[3][20];

int valid(int poz) {
    for (int i = 0; i < poz; i++)
        if (strcmp(steag[i], steag[poz]) == 0)
            return 0;
    return 1;
}

int este_solutie() {
    if (strcmp(steag[1], "verde") == 0 || strcmp(steag[1], "galben") == 0)
        return 1;
    return 0;
}

void afisare() {
    printf("%s %s %s\n", steag[0], steag[1], steag[2]);
}

void backtracking(int poz) {
    for (int i = 0; i < nr_culori; i++) {
        strcpy(steag[poz], culori[i]);
        if (valid(poz)) {
            if (poz == 2) {
                if (este_solutie())
                    afisare();
            } else {
                backtracking(poz + 1);
            }
        }
    }
}

int main() {
    backtracking(0);
    return 0;
}