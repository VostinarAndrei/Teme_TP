#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fis;
    int n=0x1177AAEE;

    if((fis=fopen("1.dat","wb"))==NULL){
        printf("nu se poate deschide fisierul\n");
        exit(EXIT_FAILURE);
    }

    fwrite(&n,sizeof(int),1,fis);

    fclose(fis);
    return 0;
}
