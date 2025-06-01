#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x,y;
}Pt;

FILE *fis;
Pt *puncte;
int nPuncte;

void adauga(double x,double y)
{
    Pt *p=(Pt*)realloc(puncte,(nPuncte+1)*sizeof(Pt));
    if(!p){
        printf("memorie insuficienta");
        free(puncte);
        fclose(fis);
        exit(EXIT_FAILURE);
    }
    puncte=p;
    puncte[nPuncte].x=x;
    puncte[nPuncte].y=y;
    nPuncte++;
}


double dist(Pt p1,Pt p2)
{
    double dx=p1.x-p2.x, dy=p1.y-p2.y;
    return sqrt(dx*dx+dy*dy);
}

int main(void)
{
    int i,j;
    double x,y;
    if((fis=fopen("pt.txt","r"))==NULL){
        printf("eroare deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    while(fscanf(fis,"%lg%lg",&x,&y)==2){
        adauga(x,y);
    }
    fclose(fis);
    if(!nPuncte){
        printf("fisier vid\n");
        exit(EXIT_FAILURE);
    }
    double dMax=0;
    int iMax=0,jMax=0;
    for(i=0;i<nPuncte;i++){
        for(j=i+1;j<nPuncte;j++){
            double d=dist(puncte[i],puncte[j]);
            if(d>dMax){
                iMax=i;
                jMax=j;
                dMax=d;
            }
        }
    }
    printf("punctele cele mai departate: (%g,%g) - (%g,%g)\n",
             puncte[iMax].x, puncte[iMax].y, puncte[jMax].x, puncte[jMax].y);
    free(puncte);
    return 0;
}
