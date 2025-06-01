#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nume[101];
    double nota;
} Student;

int cmpNote(const void *a, const void *b) {
    const Student *s1 = (const Student*)a;
    const Student *s2 = (const Student*)b;

    if (s1->nota > s2->nota) return -1;
    if (s1->nota < s2->nota) return 1;
    return strcmp(s1->nume, s2->nume);
}

int main(void) {
    int n, i;
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Numar invalid\n");
        return 1;
    }

    Student v[100];
    for (i = 0; i < n; i++) {
        if (scanf("%100s %lf", v[i].nume, &v[i].nota) != 2) {
            fprintf(stderr, "Eroare la citire\n");
            return 1;
        }
    }

    qsort(v, n, sizeof(Student), cmpNote);

    for (i = 0; i < n; i++) {
        printf("%s %.2f\n", v[i].nume, v[i].nota);
    }

    return 0;
}
