#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **linii;
int nLinii;
FILE *fin;
FILE *fout;

void eliberare()
{
    int i;
    for(i=0;i<nLinii;i++)free(linii[i]);
    free(linii);
    fclose(fin);
    fclose(fout);
}

void adauga(const char *linie)
{
    char *linieNoua=(char*)malloc((strlen(linie)+1)*sizeof(char));
    if(!linieNoua){
        printf("memorie insuficienta");
        eliberare();
        exit(EXIT_FAILURE);
        }
    strcpy(linieNoua,linie);
    char **p=(char**)realloc(linii,(nLinii+1)*sizeof(char*));
    if(!p){
        printf("memorie insuficienta");
        free(linieNoua);
        eliberare();
        exit(EXIT_FAILURE);
        }
    linii=p;
    linii[nLinii]=linieNoua;
    nLinii++;
}


int cmp(const void *p1,const void *p2)
{
    return strcmp(*(char **)p1,*(char**)p2);
}

int main(void)
{
    char linie[1000];
    int i;
    if((fin=fopen("linii.txt","rt"))==NULL){
        printf("eroare deschidere fisier de intrare\n");
        exit(EXIT_FAILURE);
        }
    while(fgets(linie,1000,fin)!=NULL){
        if(strlen(linie)<=1)continue;
        adauga(linie);
        }

    qsort(linii,nLinii,sizeof(char*),cmp);

    if((fout=fopen("sortate.txt","wt"))==NULL){
        printf("eroare deschidere fisier de iesire\n");
        exit(EXIT_FAILURE);
        }
    for(i=0;i<nLinii;i++)fputs(linii[i],fout);
    fclose(fout);
    eliberare();
    return 0;
}
