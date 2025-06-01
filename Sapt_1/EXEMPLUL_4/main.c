#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m,n,i,j;
    int **a;
    printf("m=");scanf("%d",&m);
    printf("n=");scanf("%d",&n);
    if((a=(int**)malloc(m*sizeof(int*)))==NULL){
        printf("memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<m;i++){
        if((a[i]=(int*)malloc(n*sizeof(int)))==NULL){
            for(i--;i>=0;i--)free(a[i]);
            free(a);
            printf("memorie insuficienta\n");
            exit(EXIT_FAILURE);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("a[%d][%d]=",i,j);scanf("%d",&a[i][j]);
        }
    }
    for(j=0;j<n;j++){
        int max=a[0][j];
        for(i=1;i<m;i++){
            int k=a[i][j];
            if(k>max)max=k;
        }
        printf("maximul coloanei %d este: %d\n",j,max);
    }
    for(i=0;i<m;i++)free(a[i]);
    free(a);
    return 0;
}
