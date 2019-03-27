#include <stdio.h>

#define OFFSET 97
/* a is 97, max is 122 = z */

void lees_info(int aantal[]);
void print_ster(const int rij[], int size);
void print_letterrij(const int rij[], int size);

/* --- hulpfuncties --- */
int aantalvoorkomen(const int rij[], int size);
void print_array(const int rij[], int size);

int main() {
    int aantal[26] = {0};
    int size = sizeof(aantal) / sizeof(int);

    lees_info(aantal);

    print_array(aantal, size);
    print_ster(aantal, size);
    print_letterrij(aantal, size);

    return 0;
}

void lees_info(int aantal[]) {
    int c;
    while ((c = getchar()) != '$') {
        if (c >= 65 && c <= 90)
            c += 'a' - 'A'; /* omdat c = tolower(c); niet mag */
        aantal[c - OFFSET]++;
    }
}

void print_array(const int rij[], int size) {
    int i;

    printf("\n");
    for (i = 0; i < size; i++) {
        printf("\n Letter %c :  %d  keer voor", (i + OFFSET), rij[i]);
    }
}

void print_ster(const int rij[], int size) {
    int i;

    printf("\n");
    for (i = 0; i < size; i++) {
        int a;

        printf("\n %c :   ", (i + OFFSET));
        for (a = 0; a < rij[i]; a++) {
            printf("*");
        }
    }
}
void print_letterrij(const int rij[], int size) {
    int i, meest_aantal_voorkomen;

    printf("\n\n\n\n\n");

    meest_aantal_voorkomen = aantalvoorkomen(rij, size);

    for (i = meest_aantal_voorkomen; i > 0; i--) {
        int a;
        for (a = 0; a < size; a++) {
            if (rij[a] < i) {
                printf(" %c ", ' ');
            } else if (rij[a] >= i) {
                printf(" %c ", (a + OFFSET));
            }
        }
        printf("\n");
    }
}

int aantalvoorkomen(const int rij[], int size) {
    int i, meest = 0;
    for (i = 0; i < size; i++) {
        if (rij[i] > meest)
            meest = rij[i];
    }
    return meest;
}
