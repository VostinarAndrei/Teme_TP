#include <stdio.h>

int main(int argc, char *argv[])
{
    float suma = 0.0f;
    float val;

    for (int i = 1; i < argc; i++) {
        if (sscanf(argv[i], "%f", &val) == 1) {
            suma += val;
        } else {
        }
    }

    printf("%g\n", suma);

    return 0;
}
