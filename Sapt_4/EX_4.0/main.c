#include <stdio.h>
#include <string.h>

typedef struct {
    char nume[21];
    float nota;
} Student;

int main() {
    Student s;

    printf("Nume student: ");
    fgets(s.nume, 21, stdin);
    s.nume[strcspn(s.nume, "\n")] = '\0';

    printf("Nota: ");
    scanf("%f", &s.nota);

    printf("\nStudentul introdus:\n");
    printf("Nume: %s\n", s.nume);
    printf("Nota: %.2f\n", s.nota);

    return 0;
}
