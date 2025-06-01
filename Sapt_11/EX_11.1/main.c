#include <stdio.h>
#include <math.h>

#define NMAX 100


typedef struct {
    double x, y;
    int vizitat;
} Punct;

Punct puncte[NMAX];


double distanta(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
    int n;
    printf("Numar de puncte (n < 100): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Coordonatele punctului %d (x y): ", i + 1);
        scanf("%lf %lf", &puncte[i].x, &puncte[i].y);
        puncte[i].vizitat = 0;
    }

    double x = 0.0, y = 0.0;

    printf("\nOrdinea in care se vor da gaurile:\n");

    int pasi = 0;
    while (pasi < n) {
        int cel_mai_apropiat = -1;
        double dist_min = 1e9;

        for (int i = 0; i < n; i++) {
            if (!puncte[i].vizitat) {
                double d = distanta(x, y, puncte[i].x, puncte[i].y);
                if (d < dist_min) {
                    dist_min = d;
                    cel_mai_apropiat = i;
                }
            }
        }

        x = puncte[cel_mai_apropiat].x;
        y = puncte[cel_mai_apropiat].y;
        puncte[cel_mai_apropiat].vizitat = 1;

        printf("%d. (%.2lf, %.2lf)\n", pasi + 1, x, y);
        pasi++;
    }

    return 0;
}
