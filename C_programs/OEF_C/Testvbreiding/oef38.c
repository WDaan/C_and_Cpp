#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct knoop knoop;

struct knoop {
    int getal;
    knoop* next;
};

void print_lijst(const knoop* l) {
    while (l) {
        printf("%d\t", l->getal);
        l = l->next;
    }
}

void vernietig_lijst(knoop** l) {
    knoop* h;
    while (*l) {
        h = *l;
        *l = h->next;
        free(h);
    }
}

knoop* maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens) {
    /* steeds vooraan toevoegen!! */
    knoop *l, *h;
    l = 0;
    h = l;
    int getal = bovengrens;
    int i = 0;
    while (i < aantal) {
        getal -= rand() % 3;
        h = malloc(sizeof(knoop));
        h->getal = getal;
        h->next = l;
        l = h;
        i++;
    }

    return l;
}

void verwijder_dubbels(knoop* l) {
    knoop* m;
    /*vooraan*/
    while (l) {
        while (l->next && l->getal == l->next->getal) {
            m = l->next;
            l->next = m->next;
            free(m);
        }
        l = l->next;
    }
}

int main() {
    srand(time(NULL));
    knoop* l = maak_gesorteerde_lijst_automatisch(10, 100);
    print_lijst(l);
    printf("\nnu worden dubbels verwijderd: \n");
    verwijder_dubbels(l); /* aan te vullen */
    printf("\nna verwijderen van dubbels: \n\n");
    print_lijst(l);
    vernietig_lijst(&l);
    return 0;
}