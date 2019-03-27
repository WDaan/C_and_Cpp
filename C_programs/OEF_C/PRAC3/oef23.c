#include <stdio.h>

int index_van(const double t[], int, double);
int index_van_eff(double *, int, double);

/* oef 23*/
double *plaats_van(double *, int, double);
void plaats_ptr_op_getal(const int **, int, int);

int main() {
    double getal;
    double getallen[] = {0.1, 2.3, 5.0, 2.0, 2.3, 2.9, 10.2};
    int size = sizeof(getallen) / sizeof(double);

    int geh_getallen[] = {2, 13, 15, 27, 8, 9, 3, 1, 3, 5, 4, 11, 12, 14};
    int size_geh = sizeof(geh_getallen) / sizeof(int);

    double num = 2.3;
    double *p = plaats_van(getallen, size, num);
    printf("\n index van %.1lf is : %d", num, (p - getallen));

    int num_2 = 3;
    const int *p2 = geh_getallen;
    plaats_ptr_op_getal(&p2, size_geh, num_2);
    printf("\n index van %d is : %d", num_2, (p2 - geh_getallen));
    printf("\n");
    printf("%d", *p2);

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
    for (i = 0; i < size && getal; i++) {
        if (t[i] == getal) {
            return i;
        }
    }
    return -1;
}

double *plaats_van(double *p, int size, double getal) {
    int i = 0;
    while (*(p + i) != getal && i < size) {
        i++;
    }
    return i < size ? (p + i) : NULL;
}

void plaats_ptr_op_getal(const int **p, int size, int getal) {
    int i = 0;
    while (i < size && getal != **p) {
        (*p)++;
        i++;
    }
    if (i == size) {
        *p = NULL;
    }
}
