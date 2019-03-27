#include <stdio.h>
#include <string.h>
#define AANTAL_WOORDEN 10
#define GEMIDDELDE_LENGTE_WOORDEN 7
#define TOTALE_LENGTE_ARRAY AANTAL_WOORDEN*(1 + GEMIDDELDE_LENGTE_WOORDEN)

void lees(char** const);
void schrijf(const char* const*);
void lees1(char**);
void lees2(char**);

int main() {
    char* pt[AANTAL_WOORDEN + 1]; /* zodat je ook nog een nullpointer kan wegsteken op het einde van de pointertabel */
    char t[TOTALE_LENGTE_ARRAY];
    pt[0] = t;
    printf("Geef %d woorden in:\n", AANTAL_WOORDEN);
    lees1(pt);   /* leest alle woorden in*/
    schrijf(pt); /* schrijft alle woorden onder elkaar uit */
    return 0;
}

void lees(char** pt) {
    int i;
    for (i = 0; i < AANTAL_WOORDEN; i++) {
        scanf("%s", *pt);
        *(pt + 1) = *pt + strlen(*pt) + 1;
        pt++;
    }
    *pt = 0;
}

void schrijf(const char* const* pt) {
    while (*pt) {
        printf("\n%s", *pt++);
    }
}

/*versie met indexering */
void lees1(char** pt) {
    int i = 0;
    int lengte_woord;
    int aantal_plaatsen = TOTALE_LENGTE_ARRAY;
    while (aantal_plaatsen > 1) {
        printf("Geef een woord in van maximaal %d karakter(s): ", (aantal_plaatsen - 1));
        fgets(pt[i], aantal_plaatsen, stdin);
        if (pt[i][strlen(pt[i]) - 1] == '\n') {
            pt[i][strlen(pt[i]) - 1] = 0; /* belangrijk */
        }
        lengte_woord = strlen(pt[i]);
        pt[i + 1] = pt[i] + lengte_woord + 1;
        aantal_plaatsen -= lengte_woord + 1;
        i++;
    }
    pt[i] = 0; /* laatste is nullpointer*/
}
/*versie zonder indexering */
void lees2(char** pt) {
    char** p = pt;
    int lengte_woord;
    int aantal_plaatsen = TOTALE_LENGTE_ARRAY;
    while (aantal_plaatsen > 1) {
        printf("Geef een woord in van maximaal %d karakter(s): ", (aantal_plaatsen - 1));
        fgets(*p, aantal_plaatsen, stdin);
        if (*(*p + strlen(*p) - 1) == '\n') { /* 1x * is woord, 2x * is de letter) */
            *(*p + strlen(*p) - 1) = 0;
        }
        lengte_woord = strlen(*p);
        *(p + 1) = *p + lengte_woord + 1;
        aantal_plaatsen -= lengte_woord + 1;
        p++;
    }
    *p = 0; /* laatste is nullpointer*/
}