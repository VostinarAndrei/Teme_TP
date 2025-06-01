#include <stdio.h>
#include <string.h>

#define DIM_MAX 20

char cifre[DIM_MAX];
int selectie[DIM_MAX];
int nrcif;
int k;
char maxim[DIM_MAX];

int este_mai_mare() {
    char curent[DIM_MAX];
    int p = 0;
    for(int i = 0; i < nrcif; i++)
        if(selectie[i])
            curent[p++] = cifre[i];

    curent[p] = '\0';
    if(strlen(maxim) == 0 || strcmp(curent, maxim) > 0) {
        strcpy(maxim, curent);
        return 1;
    }

    return 0;
}


void back(int poz, int pastrate) {
    if(poz == nrcif) {
        if(pastrate == nrcif - k)
            este_mai_mare();
        return;
    }

    if(pastrate < nrcif - k) {
        selectie[poz] = 1;
        back(poz + 1, pastrate + 1);
    }

    selectie[poz] = 0;
    back(poz + 1, pastrate);
}

int main() {
    char n_str[DIM_MAX];
    scanf("%s", n_str);
    scanf("%d", &k);

    strcpy(cifre, n_str);
    nrcif = strlen(cifre);
    maxim[0] = '\0';

    back(0, 0);
    printf("%s\n", maxim);

    return 0;
}
