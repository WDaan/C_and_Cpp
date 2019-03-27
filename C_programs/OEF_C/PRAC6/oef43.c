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
        printf("%s ", l->woord);
        l = l->next;
    }
}

knoop *woorden_lijst() {
    knoop *l, *h;
    char buf[81];
    int lengte;
    printf("Eerste woord: ");
    scanf("%80s", buf);
    if (strcmp(buf, "STOP") == 0) {
        l = 0;
    } else {
        /*eerste woord toevoegen*/
        l = malloc(sizeof(knoop));
        h = l;
        lengte = strlen(buf) + 1;
        h->woord = malloc(lengte * sizeof(char));
        strcpy(h->woord, buf);
        /*volgend woord inlezen*/
        printf("\nVolgende: ");
        scanf("%80s", buf);
        while (strcmp(buf, "STOP") != 0) {
            printf("ingelezen woord: %s\n", buf);
            /*volgende knoop maken*/
            h->next = malloc(sizeof(knoop));
            h = h->next;
            /*woord toevoegen*/
            lengte = strlen(buf) + 1;
            h->woord = malloc(lengte * sizeof(char));
            strcpy(h->woord, buf);

            /*volgend inlezen*/
            printf("\nVolgende: ");
            scanf("%80s", buf);
        }
        h->next = 0;
    }

    return l;
}

void print_lijst_array(knoop **arr) {
    while (*arr) {
        print_lijst(*arr);
        printf("\n");
        arr++;
    }
}

knoop **geef_array_van_lijst(int aantal) {
    knoop **arr = malloc((aantal + 1) * sizeof(knoop *));
    int x;
    /*allemaal op 0 zetten */
    for (x = 0; x < aantal + 1; x++) {
        arr[x] = 0;
    }
    int i = 0;
    int lengte;
    char buf[81];
    knoop **helper = malloc(sizeof(knoop *) * aantal);
    /*eerste woord inlezen*/
    printf("Eerste woord: ");
    scanf("%80s", buf);
    if (strcmp(buf, "STOP") == 0) {
    } else {
        i = 0;
        while (strcmp(buf, "STOP") != 0) {
            /* checken of output langer is en zodanig vrijmaken*/
            if (buf[strlen(buf) - 1] == '\n') {
                buf[strlen(buf) - 1] = 0;
            } else {
                while (getchar() != '\n')
                    ;
            }
            /*eerste koppen aanmaken*/
            if (arr[i] == 0) {
                /* eerste knoop aanmaken en helper naar wijzen */
                arr[i] = malloc(sizeof(knoop));
                helper[i] = arr[i];

            } else {
                /*volgende knoop maken*/
                helper[i]->next = malloc(sizeof(knoop));
                helper[i] = helper[i]->next;
            }

            /*woord toevoegen*/
            lengte = strlen(buf) + 1;
            helper[i]->woord = malloc(lengte * sizeof(char));
            strcpy(helper[i]->woord, buf);
            /*volgend inlezen*/
            printf("\nVolgende: ");
            scanf("%80s", buf);

            /*teller omhoog*/
            i++;
            /*teller resetten*/
            if (i == aantal) {
                i = 0;
            }
        }
        /*alle laatste knopen op 0 zetten*/
        for (i = 0; i < aantal; i++) {
            helper[i]->next = 0;
        }
    }

    free(helper);

    return arr;
}

int main() {
    knoop **arr = geef_array_van_lijst(3);
    //knoop *l = woorden_lijst();
    //print_lijst(l);
    printf("\n");
    print_lijst_array(arr);
    return 0;
}