#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct knoop knoop;

struct knoop {
    int getal;
    knoop *next;
};

void print_lijst(const knoop *);
knoop *maak_gesorteerde_lijst_automatisch(int, int);
void verwijder_dubbels(knoop **);
void free_lijst(knoop **);
void verwijder(int, knoop **);

int main() {
    srand(time(NULL));
    knoop *l = maak_gesorteerde_lijst_automatisch(10, 100);
    print_lijst(l);
    printf("\nnu worden dubbels verwijderd... \n");
    verwijder_dubbels(&l);
    printf("\nna verwijderen van dubbels: \n\n");
    print_lijst(l);
    verwijder(90, &l);
    printf("\nna verwijderen van bepaald element: \n\n");
    print_lijst(l);
    free_lijst(&l);
    return 0;
}

void print_lijst(const knoop *l) {
    while (l) {
        printf("%d\t", l->getal);
        l = l->next;
    }
}

knoop *maak_gesorteerde_lijst_automatisch(int aantal, int max) {
    int getal = max;
    getal -= rand() % 3;
    knoop *l, *h;
    l = 0;
    int i = 0;
    while (i < aantal) {
        h = malloc(sizeof(knoop));
        h->next = l;
        h->getal = getal;
        l = h;
        i++;
        getal -= rand() % 3;
    }

    return l;
}

void verwijder_dubbels(knoop **l) {
    knoop *h = *l;
    knoop *s;
    while (h) {
        /* om te checken of het volgende getal niet ook gelijk is aan h->getal*/
        /* anders blijft 95 95 staan in 95 95 95, tweede while-lus fixed het */
        while (h->next && (h->getal == h->next->getal)) {
            s = h->next;
            h->next = s->next;
            free(s);
        }
        h = h->next;
    }
}

void free_lijst(knoop **l) {
    knoop *h;
    while (*l) {
        h = *l;
        *l = h->next;
        free(h);
    }
}

void verwijder(int getal, knoop **l) {
    knoop *h;
    if ((*l)->getal == getal) {
        h = (*l)->next;
        free(*l);
        *l = h;
    } else {
        h = *l;
        while (h->next && h->next->getal != getal) h = h->next;
        if (h->next) {
            knoop *m = h->next;
            h->next = m->next;
            free(m);
        }
    }
}