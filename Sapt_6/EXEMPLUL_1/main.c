#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n;
    float x,y,e,min,max;
    printf("n=");scanf("%d",&n);
    if(n<=0||n>100){
        printf("n invalid: %d\n",n);
        exit(EXIT_FAILURE);
    }
    printf("x=");scanf("%g",&x);
    printf("y=");scanf("%g",&y);
    if(x>=y){
        printf("x=%g nu este mai mic decat y=%g\n",x,y);
        exit(EXIT_FAILURE);
    }
    max=x;
    min=y;
    for(i=0;i<n;i++){
        printf("e=");scanf("%g",&e);
        if(e<x||e>y){
            printf("element invalid: %g\n",e);
            exit(EXIT_FAILURE);
        }
        if(e<min)min=e;
        if(e>max)max=e;
    }
    printf("min: %g, max: %g\n",min,max);
    return 0;
}