#include <stdio.h>

#define num 100

int main() {
    int i;
    printf("Hello world!\n");
    for (i = num; i > 0; i--) {
        printf("%i ", i);
    }
    printf("\n");
    printf("START");

    return 0;
}