#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    int n;
    struct elem *urm;
}elem;

elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(!e){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    e->n=n;
    e->urm=urm;
    return e;
}
typedef struct{
    elem *prim;
    elem *ultim;
}Lista;
void init(Lista *lista)
{
    lista->prim=NULL;
    lista->ultim=NULL;
}

void adaugaInceput(Lista *lista,int n)
{
    elem *prim=lista->prim;
    lista->prim=nou(n,prim);
    if(!prim){
        lista->ultim=lista->prim;
    }
}

void adaugaSfarsit(Lista *lista,int n)
{
    elem *e=nou(n,NULL);
    if(lista->ultim){ // adaugare in lista nevida
        lista->ultim->urm=e;
    }else{ // adaugare in lista vida
        lista->prim=e;
    }
    lista->ultim=e;
}
void afisare(Lista *lista)
{
    elem *crt;
    for(crt=lista->prim;crt;crt=crt->urm){
        printf("%d ",crt->n);
    }
    putchar('\n');
}

void eliberare(Lista *lista)
{
    elem *p,*crt=lista->prim;
    while(crt){
        p=crt->urm;
        free(crt);
        crt=p;
    }
}
int main()
{
    Lista lista;
    init(&lista);
    adaugaSfarsit(&lista,108);
    adaugaSfarsit(&lista,-1);
    adaugaSfarsit(&lista,49);
    afisare(&lista);
    eliberare(&lista);
    return 0;
}