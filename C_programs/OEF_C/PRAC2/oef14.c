#include <stdio.h>

int index_van(const double t[], int size, double getal);
int index_van_eff(double t[], int size, double getal);

int main() {
    double getal;
    double getallen[] = {0.1, 2.3, 5.0, 2.0, 2.3, 2.9, 10.2};

    int size = sizeof(getallen) / sizeof(double);

    printf("Geef een getal in : ");

    while (scanf("%lf", &getal) == 0) {  //geeft 0 terug als geen correct getal werd ingelezen
        while (getchar() != '\n')
            ;  //buffer leegmaken
        printf("Opnieuw : ");
    }

    int index = index_van(getallen, size, getal);
    printf("\n index van %.1lf is : %d", getal, index);
    int index2 = index_van_eff(getallen, size, getal);
    printf("\n index van %.1lf is : %d", getal, index2);

    return 0;
}

int index_van(const double t[], int size, double getal) {
    int i;
    for (i = 0; i < size; i++) {
        if (t[i] == getal) {
            return i;
        }
    }
    return -1;
}

int index_van_eff(double t[], int size, double getal) {
    int i;
    for (i = 0; i < size && i < getal; i++) {
        if (t[i] == getal) {
            return i;
        }
    }
    return -1;
}
