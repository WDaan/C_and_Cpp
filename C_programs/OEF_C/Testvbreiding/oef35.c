#include <stdio.h>
#include <string.h>
#define AANTAL_WOORDEN 3
#define GEMIDDELDE_LENGTE_WOORDEN 7
#define TOTALE_LENGTE_ARRAY AANTAL_WOORDEN *(1 + GEMIDDELDE_LENGTE_WOORDEN) /*voor 0 per woord*/

void schrijf(const char *const *p) {
    while (*p) {
        puts(*p++);
    }
}

void lees(char **p) {
    int i;
    for (i = 0; i < AANTAL_WOORDEN; i++) {
        scanf("%s", *p);
        *(p + 1) = *p + strlen(*p) + 1;
        p++;
    }
    *p = 0;
}

void lees1(char **p) {
    int i = 0;
    int space = TOTALE_LENGTE_ARRAY;
    while (space > 1) {
        printf("max %d aantal char ingeven: ", space - 1);
        fgets(p[i], space, stdin);
        if (p[i][strlen(p[i]) - 1] == '\n') {
            p[i][strlen(p[i]) - 1] = 0;
        }
        p[i + 1] = p[i] + strlen(p[i]) + 1;
        space -= strlen(p[i]) + 1;
        i++;
    }
    p[i] = 0;
}

void lees2(char **pt) {
    char **p = pt;
    int space = TOTALE_LENGTE_ARRAY;
    while (space > 1) {
        printf("max %d aantal char ingeven: ", space - 1);
        fgets(*p, space, stdin);
        if (*(*p + strlen(*p) - 1) == '\n') {
            *(*p + strlen(*p) - 1) = 0; 
                }
        *(p + 1) = *p + strlen(*p) + 1;
        space -= strlen(*p) + 1;
        p++;
    }
    *p = 0;
}

int main() {
    char *pt[AANTAL_WOORDEN + 1]; /* zodat je ook nog een nullpointer kan toevoegen op het einde van de pointertabel */
    char t[TOTALE_LENGTE_ARRAY];
    pt[0] = t;
    //printf("Geef %d woorden in:\n", AANTAL_WOORDEN);
    lees2(pt); /* leest alle woorden in*/
    printf("\n");
    schrijf(pt); /* schrijft alle woorden onder elkaar uit */
    return 0;
}
