#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
 double x,y;
 }Pt;

double dist(const Pt *pt)
{
 return sqrt(pt->x*pt->x+pt->y*pt->y);
}



int cmpDist(const void *elem1,const void *elem2)
{
    const Pt *p1=(const Pt*)elem1;
    const Pt *p2=(const Pt*)elem2;
    double d1=dist(p1);
    double d2=dist(p2);
    if(d1<d2)return -1;
    if(d1>d2)return 1;

    return 0;
}
int main(void)
{
   Pt puncte[5]={{1,3},{7,5},{0,0},{-2,4},{1,1}};
   int i,n=5;
   qsort(puncte,n,sizeof(Pt),cmpDist);
   for(i=0;i<n;i++){
   printf("%g, %g\n",puncte[i].x,puncte[i].y);
   }
 return 0;
}