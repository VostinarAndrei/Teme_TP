#include <stdio.h>

struct Dreptunghi{
 int latime, lungime;
};

int main()
{
     struct Dreptunghi v[10];
     int i, n;
     int imax;

     printf("n: ");
     scanf("%d", &n);

     for (i = 0; i < n; i++){
         printf("latime %d: ", i);
         scanf("%d", &v[i].latime);
         printf("inaltime %d: ", i);
         scanf("%d", &v[i].lungime);
      }

     imax = 0;
     for (i = 1; i < n; i++){
          if (v[imax].latime * v[imax].lungime < v[i].latime * v[i].lungime){
           imax = i;
     }
   }
      printf("dreptunghi de arie maxima: %dx%d\n", v[imax].latime, v[imax].lungime);
 return 0;
}