#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;

struct knoop {
    int getal;
    knoop *next;
};

knoop *maak_lijst();
void print_lijst(const knoop *);

const knoop *pointer_naar_knoop(const knoop *l, int getal) {
    while (l) {
        if (l->getal == getal) {
            return l;
        }
        l = l->next;
    }
    return 0;
}

void vernietig_lijst(knoop **l) {
    knoop *h;
    while (*l) {
        h = *l;
        *l = h->next;
        free(h);
    }
}

void verwijder(int getal, knoop **l) {
    knoop *h;
    knoop *m;
    /*eerste knoop??*/
    if ((*l)->getal == getal) {
        h = (*l)->next;
        free(*l);
        *l = h;
    } else {
        h = *l;
        while (h->next && h->next->getal != getal) h = h->next;
        if(h->next){ /*kijken of het getal wel in de lijst staat*/
            m = h->next;
            h->next = m->next;
            free(m);
        }
    }
}

int main() {
    knoop *lijst;
    printf("Geef reeks getallen in (stop met 0):\n");
    lijst = maak_lijst();
    printf("Reeks getallen zijn:\n");
    print_lijst(lijst);
    printf("na verwijderen:\n");
    verwijder(3, &lijst);
    print_lijst(lijst);
    vernietig_lijst(&lijst);
    return 0;
}

knoop *maak_lijst() {
    knoop *l, *h;
    int getal;
    scanf("%d", &getal);
    if (getal == 0)
        l = 0;
    else {
        l = (knoop *)malloc(sizeof(knoop));
        h = l;
        h->getal = getal;
        scanf("%d", &getal);
        while (getal) {
            h->next = (knoop *)malloc(sizeof(knoop));
            h = h->next;
            h->getal = getal;
            scanf("%d", &getal);
        }
        h->next = 0;
    }
    return l;
}

void print_lijst(const knoop *l) {
    while (l) {
        printf("%d\n", l->getal);
        l = l->next;
    }
}
