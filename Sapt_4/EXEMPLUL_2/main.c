#include <stdio.h>
#include <string.h>


typedef struct{
 char nume[50];
 float pret;
} Produs;



int main()
{
    Produs produse[100];
    int i, j, op, n = 0;
    for(;;){
       printf("1. Introducere\n");
      printf("2. Afisare\n");
      printf("0. Iesire\n");
      printf("operatia: ");
      scanf("%d", &op);

  switch (op){
      case 1:
       getchar();
       printf("nume: ");
       fgets(produse[n].nume, 50, stdin);
       produse[n].nume[strcspn(produse[n].nume, "\n")] = '\0';
       printf("pret: ");
       scanf("%g", &produse[n].pret);
       n++;
       break;

   case 2:
     for (i = 0; i < n; i++){
       printf("%s %g\n", produse[i].nume, produse[i].pret);
     }
    break;

   case 0:
     return 0;
   default:
    printf("operatie necunscuta\n");
  }
 }
}