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
knoop *merge(knoop **, knoop **);

int main() {
    srand(time(NULL));
    knoop *m = maak_gesorteerde_lijst_automatisch(10, 1000);
    knoop *n = maak_gesorteerde_lijst_automatisch(5, 1000);
    printf("\nLIJST m:\n");
    print_lijst(m);
    printf("\nLIJST n:\n");
    print_lijst(n);
    printf("\nDeze worden gemerged. \n\n");
    knoop *mn = merge(&m, &n);
    printf("\nLIJST m: \n");
    print_lijst(m);
    printf("\nLIJST n: \n");
    print_lijst(n);
    printf("\nRESULTAAT: \n");
    print_lijst(mn);
    free_lijst(&mn); /* elementen uit lijst verwijderen*/
    free(mn);        /*lijst zelf verwijderen */
    return 0;
}

knoop *merge(knoop **m, knoop **n) {
    knoop *helper[3]; /*0 voor l, 1 voor m en 2 voor n*/
    knoop *l = 0;     /*deze bevat de volledige lijst*/
    helper[0];
    helper[1] = *m;
    helper[2] = *n;
    /*checken 1 vd beide leeg*/
    if (*m == 0) {
        l = *n;
        *n = 0;
        return l;
    } else if (*n == 0) {
        l = *m;
        *m = 0;
        return l;
    }
    /*allereerste toevoegen*/
    if (helper[1]->getal < helper[2]->getal) {
        l = helper[1];
        helper[1] = helper[1]->next;
        helper[0] = l;
    } else {
        l = helper[2];
        helper[2] = helper[2]->next;
        helper[0] = l;
    }
    /*de rest toevoegen*/
    while (helper[1] && helper[2]) {
        if (helper[1]->getal < helper[2]->getal) {
            helper[0]->next = helper[1];
            helper[1] = helper[1]->next;
        } else {
            helper[0]->next = helper[2];
            helper[2] = helper[2]->next;
        }
        helper[0] = helper[0]->next;
    }
    if (helper[1]) {
        helper[0]->next = helper[1]; /*gwn alle rest van m aan l hangen, blijft toch enkel elementen van m over*/
    }
    if (helper[2]) {
        helper[0]->next = helper[2]; /* alle rest van n aan l hangen*/
    }
    *m = 0;
    *n = 0;
    return l;
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
    h = 0;
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
