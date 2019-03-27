#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int waarde, aantal_delers;
    int *delers;
} Deeltal;

void schrijf_ints(const int *t) {
    printf("%d", *t++); /* eerste printen en opschuiven */
    while (*t) {
        printf("-%d", *t++);
    }
}

void schrijf_deeltal(const Deeltal *d) {
    printf("%d\t", d->waarde);
    schrijf_ints(d->delers);
}

void free_delers(Deeltal *d) {
    printf("deeltallen van %d vrijgeven...", d->waarde);
    free(d->delers);
}

void free_deeltallen(Deeltal *d, int aantal) {
    int i;
    printf("tabel deeltallen vrijgeven");
    for (i = 0; i < aantal; i++) {
        free_delers(&d[i]);
    }
}

void free_deeltallen_volledig(Deeltal **d, int aantal) {  //** om tabel zelf te kunnen free'en
    int i;
    printf("tabel deeltallen vrijgeven");
    for (i = 0; i < aantal; i++) {
        free_delers(&(*d)[i]);
    }
    free(*d);
}

int main() {
    Deeltal d;
    d.waarde = 6;
    d.aantal_delers = 3;
    d.delers = malloc(sizeof(int) * 3);
    d.delers[0] = 1;
    d.delers[1] = 2;
    d.delers[2] = 3;
    schrijf_deeltal(&d);

    return 0;
}