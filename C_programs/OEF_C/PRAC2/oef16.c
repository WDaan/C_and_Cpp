#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 120
#define MIN 100

void print_array(const int rij[], int size);
void komen_niet_voor(const int rij[], int size);

int main() {
    int getallen[20] = {1};
    int size = sizeof(getallen) / sizeof(int);

    srand(time(NULL));

    int i, num;
    for (i = 0; i < 20; i++) {
        num = rand() % (MAX - MIN + 1) + MIN;
        getallen[i] = num;
    }
    print_array(getallen, size);
    komen_niet_voor(getallen, size);

    return 0;
}

void print_array(const int rij[], int size) {
    printf("\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("\nGetal nr %d :  %d ", i, rij[i]);
    }
}

void komen_niet_voor(const int rij[], int size) {  //moeten in stijgende grootte uitgeprint worden!!
    printf("\n-------komen niet voor-------");

    int i;
    for (i = MIN; i <= MAX; i++) {
        int a = 0;
        while (a < size && rij[a] != i) {
            a++;
        }
        if (a >= size)
            printf("\n Getal : %d ", i);
    }
}