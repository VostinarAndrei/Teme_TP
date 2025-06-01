#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
double maxN(int n,...)
{
    va_list va;
    va_start(va,n);
    double max=va_arg(va,double);
    while(--n){
        double e=va_arg(va,double);
        if(max<e)max=e;
    }
    va_end(va);
    return max;
}
int main()
{
    printf("%g\n",maxN(3,8,0,5));
     printf("%g\n",maxN(3,(double)8,0.0,(float)5)); // apel corect => 8
    return 0;
}