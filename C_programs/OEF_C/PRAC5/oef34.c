#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int waarde, aantal_delers;
    int *delers;
} Deeltal;

void schrijf_ints(const int *);
void schrijf_deeltal(const Deeltal *);
void schrijf_deeltallen(const Deeltal *, const int);

int aantal_delers_van(const Deeltal *);
int *delers_van(const Deeltal *, const int);

void lees_deeltal(Deeltal *);
void lees_deeltallen(Deeltal *, const int);

void free_delers(Deeltal *);
void free_deeltallen(Deeltal *, int);
void free_deeltallen_volledig(Deeltal **, int);

const Deeltal *zoek(const int, const Deeltal *, const int);

int main() {
    Deeltal d;
    Deeltal *t;
    int i, a;
    lees_deeltal(&d);

    schrijf_deeltal(&d);
    printf("\n");

    /*nu een aantal */

    printf("\nHoeveel Deeltallen wil je ingeven? ");
    scanf("%d", &a);

    /* array aanmaken/ grootte voorzien */
    t = (Deeltal *)malloc(a * sizeof(Deeltal));

    /*inlezen*/
    lees_deeltallen(t, a);

    /*uitprinten*/
    schrijf_deeltallen(t, a);

    /*zoeken*/
    const Deeltal *gevonden = zoek(5, t, a);
    if (gevonden != NULL) {
        schrijf_deeltal(gevonden);
    }

    /*vrijgeven */
    free_delers(&d);

    free_deeltallen_volledig(&t, a);

    return 0;
}

void schrijf_ints(const int *t) {
    printf("%d", *t++); /* eerste printen en opschuiven */
    while (*t) {
        printf("-%d", *t++);
    }
}

void schrijf_deeltal(const Deeltal *d) {
    printf("\n%d\t", d->waarde);
    schrijf_ints(d->delers);
    printf("\nAantal delers: %d", d->aantal_delers);
}

int aantal_delers_van(const Deeltal *d) {
    int i, counter = 0;
    for (i = 1; i <= d->waarde / 2; i++) {
        if (d->waarde % i == 0) {
            counter++;
        }
    }
    return counter;
}

int *delers_van(const Deeltal *d, const int aantal) {
    int *d_array;
    int i, a = 0;
    d_array = (int *)malloc(aantal * sizeof(int));

    for (i = 1; i <= d->waarde / 2; i++) {
        if (d->waarde % i == 0) {
            *(d_array + a) = i;
            a++;
        }
    }
    *(d_array + a) = 0;
    return d_array;
}

void lees_deeltal(Deeltal *d) {
    printf("\nWaarde: ");
    scanf("%d", &d->waarde);
    if (d->waarde < 0) {
        d->waarde *= -1;
    }
    d->aantal_delers = aantal_delers_van(d);
    d->delers = delers_van(d, d->aantal_delers);
}

void lees_deeltallen(Deeltal *t, const int aantal) {
    int i;
    /*t = malloc(aantal * sizeof(Deeltal));*/
    for (i = 0; i < aantal; i++) {
        lees_deeltal((t + i));
    }
}

void schrijf_deeltallen(const Deeltal *t, const int aantal) {
    int i;
    for (i = 0; i < aantal; i++) {
        schrijf_deeltal(&t[i]);
    }
}

const Deeltal *zoek(const int waarde, const Deeltal *t, const int aantal) {
    int i = 0;
    while (i < aantal && t[i].waarde != waarde) {
        i++;
    }
    return (i == aantal ? 0 : &t[i]);
}

void free_delers(Deeltal *g) {
    /* belangrijk om te controleren of je goed bezig bent: */
    printf("\nik geef (delers van) dit deeltal vrij: %d", g->waarde);
    free(g->delers);
}
void free_deeltallen(Deeltal *g, int aantal) {
    int i;
    printf("\nFree tabel met %d deeltallen:", aantal);
    for (i = 0; i < aantal; i++) {
        free_delers(&g[i]);
    }
}
void free_deeltallen_volledig(Deeltal **g, int aantal) {
    int i;
    printf("\nFree tabel met %d deeltallen:", aantal);
    for (i = 0; i < aantal; i++) {
        free_delers(&(*g)[i]);
    }
    printf("\nTabel zelf vrijgeven");
    free(*g);
}