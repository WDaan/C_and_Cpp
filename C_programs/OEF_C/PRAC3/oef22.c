#include <stdio.h>

void zoek_extremen(int *, int, int *, int *);
void zoek_extremen_rec(int[], int, int *, int *);

int main() {
    int t[] = {2, 3, 5, 55, 6, 22, 44, 34, 23, 89, 4, 2, 3, 5, 77, 89, 49};
    int max, min;
    int size = sizeof(t) / sizeof(int);
    //zoek_extremen(t, size, &max, &min);
    zoek_extremen_rec(t, size, &max, &min);
    printf("MAX : %d", max);
    printf("\nMIN : %d", min);

    return 0;
}

void zoek_extremen(int *p, int size, int *pmax, int *pmin) {
    int i;
    *pmax = *p;
    *pmin = *p;
    for (i = 1; i < size; i++)  //want eerste is gechecht bij init van max en min
    {
        if (*pmax < *(p + i)) {
            *pmax = *(p + i);
        } else if (*pmin > *(p + i)) {
            *pmin = *(p + i);
        }
    }
}

void zoek_extremen_rec(int t[], int size, int *pmax, int *pmin) {
    if (*pmax < *t) {
        *pmax = *t;
    } else if (*pmin > *t) {
        *pmin = *t;
    }

    if (size > 1) {
        zoek_extremen_rec(&t[1], size - 1, pmax, pmin);
    }
}