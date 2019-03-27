#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;

struct knoop {
    int getal;
    knoop *next;
};

knoop *maak_lijst();
void voeg_getal_toe(int, knoop **);
void voeg_getal_toe2(int, knoop **);
void print_lijst(const knoop *);

int main() {
    printf("Geef reeks getallen in (stop met 0):\n");
    knoop *lijst = maak_lijst();
    print_lijst(lijst);
    printf("\nNa toevoegen ... \n");
    voeg_getal_toe2(4, &lijst);
    print_lijst(lijst);

    return 0;
}

knoop *maak_lijst() {
    knoop *l, *h;
    int getal;
    scanf("%d", &getal);
    if (getal == 0)
        l = 0;
    else {
        l = (knoop *)malloc(sizeof(knoop));  //l is de kop (denkik)
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

void voeg_getal_toe(int g, knoop **l) {
    knoop *h, *m;
    if (*l == 0 || g <= (*l)->getal) {
        h = (knoop *)malloc(sizeof(knoop));
        h->getal = g;
        h->next = *l;
        *l = h; /* vooraan toevoegen */
    } else {
        h = *l;
        while (h->next != 0 && h->next->getal < g) h = h->next;
        m = h->next;
        h->next = (knoop *)malloc(sizeof(knoop));
        h = h->next;
        h->getal = g;
        h->next = m;
    }
}

void voeg_getal_toe2(int getal, knoop ** l){
    knoop *h  = *l;
    knoop * naar_achter;
    while(h->next && h->next->getal <= getal) h = h->next;  
}

