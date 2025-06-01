#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void citire(const char *fmt,...)
{
    va_list va;
    va_start(va,fmt);
    int *addrInt;
    float *addrFloat;
    char *addrStr;
    for( ; ; fmt++ ){
        switch(*fmt){
            case '\0':
                va_end(va);
            return;
            case 'd':
                addrInt=va_arg(va,int*);
            scanf("%d",addrInt);
            break;
            case 'f':
                addrFloat=va_arg(va,float*);
            scanf("%g",addrFloat);
            break;
            case 's':
                addrStr=va_arg(va,char*);
            scanf("%s",addrStr);
            break;
        }
    }
}
int main()
{
    int n,m;
    float x;
    char buf[100];
    printf("introduceti n, m, y si buf:\n");
    citire("ddfs",&n,&m,&x,buf);
    printf("n=%d, m=%d, x=%g, buf=%s\n",n,m,x,buf);
    return 0;
}