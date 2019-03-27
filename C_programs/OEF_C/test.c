#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int t[10];
    int i, getal;
    int max = 100;
    getal = max;
    getal -= (rand() % 2);
    for (i = 0; i < 10; i++) {
        t[i] = getal;
        getal -= (rand() % 2);
    }
    t[i] = getal;

    printf("\n");
    int a;
    for (a = 0; a < 10; a++) {
        printf("%d\t", t[a]);
    }

    return 0;
}
