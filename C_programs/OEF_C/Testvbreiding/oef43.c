#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct knoop knoop;
struct knoop {
    char *woord;
    knoop *next;
};

void print_lijst(knoop *l) {
    while (l) {
        printf("%s ", l->woord);
        l = l->next;
    }
}

void print_all(knoop **arr, int aantal) {
    int i = 0;
    for (i = 0; i < aantal; i++) {
        print_lijst(arr[i]);
        printf("\n");
    }
}

knoop **geef_array_van_lijsten(int aantal) {
    knoop **arr = malloc(sizeof(knoop *) * aantal);
    knoop **helper = malloc(sizeof(knoop *) * aantal);
    int x;
    /*allemaal op 0 zetten */
    for (x = 0; x < aantal; x++) {
        arr[x] = 0;
    }
    int lengte;
    char buf[81];
    int i = 0;
    printf("Woord ingeven: ");
    scanf("%80s", buf);
    if (strcmp(buf, "STOP") == 0) {
        arr = 0;
        return arr;
    } else {
        while (strcmp(buf, "STOP") != 0) {
            /* checken of output langer is en zodanig vrijmaken*/
            if (buf[strlen(buf) - 1] == '\n') {
                buf[strlen(buf) - 1] = 0;
            } else {
                while (getchar() != '\n')
                    ;
            }
            /* om deze if te kunnen checken dient de forloop met alles op 0*/
            if (arr[i] == 0) {
                arr[i] = malloc(sizeof(knoop));
                helper[i] = arr[i];

            } else {
                helper[i]->next = malloc(sizeof(knoop));
                helper[i] = helper[i]->next;
            }
            lengte = strlen(buf) + 1;
            helper[i]->woord = malloc(sizeof(char) * lengte);
            strcpy(helper[i]->woord, buf);
            helper[i]->next = 0;

            printf("Woord ingeven: ");
            scanf("%80s", buf);

            i++;
            if (i == aantal) {
                i = 0;
            }
        }
    }

    free(helper);
    return arr;
}

int main() {
    knoop **arr = geef_array_van_lijsten(3);
    printf("\n");
    print_all(arr, 3);
    return 0;
}