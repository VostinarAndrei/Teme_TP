#include <stdio.h>
#include <math.h>

const double G = 6.674e-11;
int n;
int ma_int, mb_int, m_int, d_int;
int start, end, mijloc;


void calculeaza_si_afiseaza(int start, int end) {
    if (start > end) return;

    mijloc = (start + end) / 2;

    int x = (mijloc * d_int) / n;
    int dist_ma = x;
    int dist_mb = d_int - x;

    double F_ma = G * (double)ma_int * (double)m_int / ((double)(dist_ma * dist_ma));
    double F_mb = G * (double)mb_int * (double)m_int / ((double)(dist_mb * dist_mb));
    double F = F_mb - F_ma;

    printf("Pas %d: pozitie %d m, Forta F = %e N\n", mijloc, x, F);

    calculeaza_si_afiseaza(start, mijloc - 1);
    calculeaza_si_afiseaza(mijloc + 1, end);
}

int main() {
    printf("ma mb m d n = ");
    scanf("%d %d %d %d %d", &ma_int, &mb_int, &m_int, &d_int, &n);

    calculeaza_si_afiseaza(0, n);

    return 0;
}
