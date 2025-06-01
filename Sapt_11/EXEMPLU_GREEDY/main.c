#include <stdio.h>

typedef struct{
    int val; // valoarea in bani
    char *nume;
}Tip;

#define NTIPURI 10

Tip tipuri[NTIPURI]={{50000,"500 lei"},{20000,"200 lei"},{10000,"100 lei"},{5000,"50 lei"},{1000,"10 lei"},
{500,"5 lei"},{100,"1 leu"},{50,"50 bani"},{10,"10 bani"},{1,"1 ban"}};

int main()
{
    float valLei;
    printf("valoare: ");scanf("%g",&valLei);
    int valBani=(int)(valLei*100);
    int iTip=0;
    while(valBani){
        int n=valBani/tipuri[iTip].val;
        if(n){
            printf("%d x %s\n",n,tipuri[iTip].nume);
            valBani-=n*tipuri[iTip].val;
        }
        ++iTip;
    }
    return 0;
}