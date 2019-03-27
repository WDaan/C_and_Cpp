#include <stdio.h>

void schrijf_cstring(const void *s) {
    const char *const *s2 = (const char *const *)s;
    printf("%s", *s2);
}
void schrijf_int(const void *t) {
    const int *t2 = (const int *)t;
    printf("%d", *t2);
}
void schrijf_double(const void *t) {
    const double *t2 = (const double *)t;
    printf("%.1lf", *t2);
}

void schrijf_array(const void *arr, int e_size, int aantal, char teken, void (*schrijf)(const void *)) {
    const char *t = (const char *)arr;
    int i;
    schrijf(t);
    for (i = 1; i < aantal; i++) {
        printf("%c", teken);
        t += e_size;
        schrijf(t);
    }
}

int main() {
    const char *namen[] = {"Evi", "Jaro", "Timen", "Youri", "Ashaf", "Jennifer"};
    int leeftijden[] = {21, 30, 18, 14, 22, 19};
    double scores[] = {0.5, 1.6, 8.2, -2.4};

    /*
    schrijf_cstring(namen);
    printf("\n");
    schrijf_int(leeftijden);
    printf("\n");
    schrijf_double(scores);
    */

    schrijf_array(namen, sizeof(char *), sizeof(namen) / sizeof(char *), ';', schrijf_cstring);
    printf("\n");
    schrijf_array(leeftijden, sizeof(int), sizeof(leeftijden) / sizeof(int), '-', schrijf_int);

    printf("\n");
    schrijf_array(scores, sizeof(double), sizeof(scores) / sizeof(double), '~', schrijf_double);

    return 0;
}
