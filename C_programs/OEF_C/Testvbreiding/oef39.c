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

knoop* merge(knoop** m, knoop** n) {
    knoop* mn;
    knoop* h1;
    knoop* h2 = *m;
    knoop* h3 = *n;
    /* checken op leeg */
    if (*m == 0) {
        mn = *n;
        *n = 0;
        return mn;
    } else if (*n == 0) {
        mn = *m;
        *m = 0;
        return mn;
    }
    /* eerste toevoegen */
    if (h2->getal < h3->getal) {
        mn = h2;
        h2 = h2->next;
        h1 = mn;
    } else {
        mn = h3;
        h3 = h3->next;
        h1 = mn;
    }
    /*mergen zelf*/
    while (h2 && h3) {
        if (h2->getal < h3->getal) {
            h1->next = h2;
            h2 = h2->next;
        } else {
            h1->next = h3;
            h3 = h3->next;
        }
        h1 = h1->next;
    }
    /*rest toevoegen*/
    if (h2) {
        h1->next = h2;
    } else {
        h1->next = h3;
    }
    *m = 0;
    *n = 0;
    return mn;
}

int main() {
    srand(time(NULL));
    knoop* m = maak_gesorteerde_lijst_automatisch(10, 1000);
    knoop* n = maak_gesorteerde_lijst_automatisch(5, 1000);
    printf("\nLIJST m:\n");
    print_lijst(m);
    printf("\nLIJST n:\n");
    print_lijst(n);
    printf("\nDeze worden gemerged. \n\n");
    knoop* mn = merge(&m, &n);
    printf("\nLIJST m: \n");
    print_lijst(m);
    printf("\nLIJST n: \n");
    print_lijst(n);
    printf("\nRESULTAAT: \n");
    print_lijst(mn);
    vernietig_lijst(&mn);
    return 0;
}