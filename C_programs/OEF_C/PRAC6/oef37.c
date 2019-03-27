#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;

struct knoop {
    int getal;
    knoop* next;
};

void voeg_vooraan_toe(int, knoop**);
void print_lijst(const knoop*);
void print_lijst_rec(const knoop*);

void free_lijst(knoop**);

int main() {
    knoop* l = 0;
    voeg_vooraan_toe(7, &l);
    voeg_vooraan_toe(3, &l);
    print_lijst(&l);
    free_lijst(&l);
    return 0;
}

void voeg_vooraan_toe(int getal, knoop** l) {
    knoop* h = malloc(sizeof(knoop));
    h->next = *l;
    h->getal = getal;
    *l = h;
}

void print_lijst(const knoop* l) {
    while (l) {
        printf("\nGetal : %d", l->getal);
        l = l->next;
    }
    printf("X\n");
}

void print_lijst_rec(const knoop* l) {
    if (l) {
        printf("\nGetal : %d", l->getal);
        print_lijst_rec(l->next);
    } else {
        printf("X\n");
    }
}

void free_lijst(knoop** l) {
    knoop* h;
    while (*l) {
        h = *l;
        *l = h->next;
        free(h);
    }
}
