#include <stdio.h>

#define DIM_MAX_N 15

int p[DIM_MAX_N] = {0};
int folosit[DIM_MAX_N] = {0};

int este_valid(int n){
    int mij = n / 2;
    for(int i = 0; i < mij - 1; i++)
        if(p[i] < p[i + 1])
            return 0;
    for(int i = mij; i < n - 1; i++)
        if(p[i] > p[i + 1])
            return 0;

    return 1;
}

void afisare(int n){
    for(int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");
}

void backtracking(int n, int poz){
    for(int i = 1; i <= n; i++){
        if(!folosit[i]){
            p[poz] = i;
            folosit[i] = 1;
            if(poz == n - 1){
                if(este_valid(n))
                    afisare(n);
            } else {
                backtracking(n, poz + 1);
            }

            folosit[i] = 0;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    backtracking(n, 0);
    return 0;
}
