#include <stdio.h>
#include <stdlib.h>

int split(char **componente,char *buf,char sep)
{
    int start,i,n=0;
    for(start=i=0;buf[i];i++){
        if(buf[i]==sep){
            componente[n]=buf+start;
            buf[i]='\0';
            n++;
            start=i+1;
        }
    }
    if(start!=i){
        componente[n]=buf+start;
        n++;
    }
    return n;
}

int main(void)
{
    FILE *fis;
    if((fis=fopen("studenti.txt","r"))==NULL){
        printf("eroare deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    char linie[1000];
    char *componente[100];
    int i,n;
    while(fgets(linie,1000,fis)!=NULL){
        n=split(componente,linie,',');
        if(n<=1)continue;
        double suma=0;
        for(i=1;i<n;i++){
            suma+=atof(componente[i]);
        }
        printf("%s: %g\n",componente[0],suma/(n-1));
    }
    fclose(fis);
    return 0;
}
