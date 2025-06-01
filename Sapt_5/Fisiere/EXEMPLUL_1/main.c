#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fis;
    int i,n;
    printf("n=");scanf("%d",&n);
    if((fis=fopen("out.txt","w"))==NULL){
        printf("eroare deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<=n;i++){
        if(i%2==0){
            fprintf(fis,"%d este par\n",i);
        }else{
            fprintf(fis,"%d este impar\n",i);
        }
    }
    fclose(fis);
    return 0;
}
