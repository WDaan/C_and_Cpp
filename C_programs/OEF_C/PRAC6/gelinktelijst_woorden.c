#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct knoop knoop;

struct knoop {
    char *woord;
    knoop *next;
};

void print_lijst(const knoop *l) {
    while (l) {
        printf("%s\t", l->woord);
        l = l->next;
    }
}

knoop **geef_array_van_lijst(int aantal) {
    knoop **arr = 0;

    return arr;
}

knoop *woorden_lijst() {
    knoop *l, *h;
    char buf[80];
    int lengte;
    printf("Eerste woord: ");
    scanf("%s", buf);
    if (strcmp(buf, "STOP") == 0) {
        l = 0;
    } else {
        /*eerste woord toevoegen*/
        l = malloc(sizeof(knoop));
        h = l;
        lengte = strlen(buf)+1;
        h->woord = malloc(lengte * sizeof(char));
        strcpy(h->woord, buf);
        /*volgend woord inlezen*/
        printf("\nVolgende: ");
        scanf("%s", buf);
        while (strcmp(buf, "STOP") != 0) {
            printf("ingelezen woord: %s\n", buf);
            /*volgende knoop maken*/
            h->next = malloc(sizeof(knoop));
            h = h->next;
            /*woord toevoegen*/
            lengte = strlen(buf)+1;
            h->woord = malloc(lengte * sizeof(char));
            strcpy(h->woord, buf);
            
            /*volgend inlezen*/
            printf("\nVolgende: ");
            scanf("%s", buf);
        }
        h->next = 0;
    }

    return l;
}

int main() {
    knoop **arr = geef_array_van_lijst(3);
    knoop *l = woorden_lijst();
    print_lijst(l);
    return 0;
}