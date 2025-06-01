#include <stdio.h>

int f1(int a,int b)
{
 return a+b;
}

int f2(int a,int b)
{
 return a-b;
}


int main(void)
{
   int a=7,b=5;
   int (*pf)(int,int);
   pf=&f1;
   printf("op(%d,%d)=>%d\n",a,b,(*pf)(a,b));
   pf=&f2;
   printf("op(%d,%d)=>%d\n",a,b,(*pf)(a,b));
 return 0;
}