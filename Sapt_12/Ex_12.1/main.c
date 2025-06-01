#include <stdio.h>

#define DIM_MAX_N 50

int nr[DIM_MAX_N] = {0};

int este_solutie(int k, int n){
    int ones = 0;
    for(int i = 0; i <n; i++)
        if(nr[i]==1)
            ones++;
    return ones==k;
}

void afisare(int n){
    int numar = 0;
    for(int i = 0; i < n; i++)
        numar = numar * 10 + nr[i];
    printf("%d\n", numar);
}

void backtracking(int n, int k, int poz){
    for(int i = 0; i <= 9; i++){
        nr[poz] = i;

        if(poz == 0 && i == 0)
            continue;

        if(poz == n - 1){
            if(este_solutie(k, n))
                afisare(n);
        }
        else
            backtracking(n, k, poz + 1);

    }
}



int main(){
    int n,k;
    scanf("%d%d", &n, &k);
    backtracking(n,k,0);
    return 0;
}